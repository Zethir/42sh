/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/15 17:31:44 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

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

void		exec_process(t_hub *info, t_process *process, int *iofile)
{
	init_parse(info, process->cmd);
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
	wait_for_process(process);
	free(info->parse);
	if (iofile[0] != 0)
		close(iofile[0]);
	if (iofile[1] != 1)
		close(iofile[1]);
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

static void	exec_job(t_hub *info)
{
	t_job	*job;

	job = info->job;
	while (job)
	{
		if (job->linker == 0)
			job = job->next;
		launch_process(info, job);
		if (!job_success(job) && job->linker == AND)
		{
			while (job->next && job->linker == AND)
				job = job->next;
		}
		else if (job_success(job) && job->linker == OR)
		{
			while (job->next && job->linker == OR)
				job = job->next;
		}
		job = job->next;
	}
	free_job(info->job);
}

void	parse_cmd(t_hub *info)
{
	t_job		*job;
	t_token		*token;

	token = info->lex->token;
	info->job = init_job();
	job = info->job;
	init_stdio(info);
	while (token)
	{
		if (token->token_value == PIPE)
		{
			token_pipe(info, job, token);
			token = token->next;
		}
		else if (token->token_value == AND || token->token_value == OR ||
				token->token_value == SEPARATOR)
		{
			token_linker(info, job, token);
			token = token->next;
		}
		else
			token = hub_redir(info, token);
	}
	info->job = job;
	exec_job(info);
}
