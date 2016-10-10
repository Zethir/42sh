/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/10 18:43:10 by cboussau         ###   ########.fr       */
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

static void	exec_process(t_hub *info, t_process *process, int *iofile)
{
	init_parse(info, process);
	if (check_builtin(info->parse->argv[0]))
	{
		process->stdio[0] = iofile[0];
		process->stdio[1] = iofile[1];
		launch_builtin(info, process);
	}
	else if ((info->parse->pid = fork()) == 0)
	{
		if (iofile != 0)
			process->stdio[0] = iofile[0];
		if (iofile[1] != 1)
			process->stdio[1] = iofile[1];
		launch_bin(info, process);
	}
	free(info->parse);
}

static void	launch_process(t_hub *info, t_job *job)
{
	t_process	*process;
	int			iofile[2];
	int			pipefd[2];

	process = job->process;
	iofile[0] = 0;
	while (process)
	{
		if (process->next)
		{
			pipe(pipefd);
			iofile[1] = pipefd[1];
		}
		else
			iofile[1] = 1;
		exec_process(info, process, iofile);
		iofile[0] = pipefd[0];
		process = process->next;
	}
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
		if (!job_sucess(job) && job->linker == AND)
		{
			while (job->next && job->next->linker == AND)
				job = job->next;
		}
		else if (job_success(job) && job->linker == OR)
		{
			while (job->next && job->next->linker == OR)
				job = job->next;
		}
		job = job->next;
	}
}

void	parse_cmd(t_hub *info)
{
	t_job		*job;
	t_token		*token;
	int			stdio[3];

	token = info->lex->token;
	info->job = init_job();
	job = info->job;
	stdio[0] = 0;
	stdio[1] = 1;
	stdio[2] = 2;
	while (token)
	{
		if (token->token_value == PIPE)
		{
			create_process(job, token, stdio);
		}
		else if (token->token_value == AND || token->token_value == OR ||
				token->token_value == SEPARATOR)
		{
			create_process(job, token, stdio);
			create_job(job, token);
			job->process = NULL;
		}
		else
			token = hub_redir(job, token);
		token = token->next;
	}
	info->job = job;
//	print_job_process(job);
}
