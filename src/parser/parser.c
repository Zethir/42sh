/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/11 18:13:02 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

/*static void	print_job_process(t_job *job)
{
	while (job)
	{
		if (job->linker == 0)
			job = job->next;
		while (job->process)
		{
			printf("process->cmd = %s\n", job->process->cmd);
			job->process = job->process->next;
		}
		printf("linker = %d\n", job->linker);
		job = job->next;
	}
}*/

static int	job_success(t_job *job)
{
	t_process *process;

	process = job->process;
	while (process)
	{
		if (process->completed == 0)
			return (0);
		process = process->next;
	}
	return (1);
}

static void	exec_process(t_hub *info, t_process *process, int *iofile)
{
	init_parse(info, process);
	if (check_builtins(info->parse->argv[0]))
	{
		process->stdio[0] = iofile[0];
		process->stdio[1] = iofile[1];
		launch_builtin(info, process);
	}
	else if ((info->parse->pid = fork()) == 0)
	{
		if (iofile[0] != 0)
			process->stdio[0] = iofile[0];
		if (iofile[1] != 1)
			process->stdio[1] = iofile[1];
		launch_bin(info, process);
	}
	free(info->parse);
	if (iofile[0] != 0)
		close(iofile[0]);
	if (iofile[1] != 1)
		close(iofile[1]);
	wait(0);
}

static void	launch_process(t_hub *info, t_job *job)
{
	t_process	*process;
	int			iofile[2];
	int			pipefd[2];

	process = job->process;
	iofile[0] = 0;
	while (job->process)
	{
		if (job->process->next)
		{
			pipe(pipefd);
			iofile[1] = pipefd[1];
		}
		else
			iofile[1] = 1;
		exec_process(info, job->process, iofile);
		iofile[0] = pipefd[0];
		job->process = job->process->next;
	}
	job->process = process;
}

void	exec_job(t_hub *info)
{
	t_job	*job;

	job = info->job;
	while (job)
	{
		if (job->linker == 0)
			job = job->next;
		launch_process(info, job);
		if (job_success(job) == 1 && job->linker == AND)
		{
			while (job->next && job->linker == AND)
				job = job->next;
		}
		else if (job_success(job) == 0 && job->linker == OR)
		{
			while (job->next && job->linker == OR)
				job = job->next;
		}
		job = job->next;
	}
}

void	parse_cmd(t_hub *info)
{
	t_job		*job;
	t_token		*token;

	token = info->lex->token;
	info->job = init_job();
	job = info->job;
	if (!(info->stdio = (int *)malloc(sizeof(int) * 3)))
		return (NULL);
	info->stdio[0] = 0;
	info->stdio[1] = 1;
	info->stdio[1] = 2;
	while (token)
	{
		if (token->token_value == PIPE)
		{
			create_process(job, token, info->stdio);
			token = token->next;
		}
		else if (token->token_value == AND || token->token_value == OR ||
				token->token_value == SEPARATOR)
		{
			create_process(job, token, info->stdio);
			create_job(job, token);
			job->process = NULL;
			token = token->next;
		}
		else
			token = hub_redir(info, token);
	}
	info->job = job;
//	print_job_process(job);
}
