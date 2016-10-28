/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 14:00:09 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int		job_success(t_job *job)
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

void			exec_process(t_shell *sh, t_job *job, int *iofile)
{
	t_parse *parse;

	parse = init_parse(sh, job->process->cmd);
	if (check_builtins(parse->argv[0]))
	{
		if (iofile[0] != 0)
			job->process->stdio[0] = iofile[0];
		if (iofile[1] != 1)
			job->process->stdio[1] = iofile[1];
		launch_builtin(sh, parse, job);
	}
	else if ((parse->pid = fork()) == 0)
	{
		if (iofile[0] != 0)
			job->process->stdio[0] = iofile[0];
		if (iofile[1] != 1)
			job->process->stdio[1] = iofile[1];
		launch_bin(sh, parse, job->process);
	}
	wait_for_process(job->process);
	free_parse(&parse);
}

static void		launch_process(t_shell *sh, t_job *job)
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
		exec_process(sh, job, iofile);
		if (iofile[0] != 0)
			close(iofile[0]);
		if (iofile[1] != 1)
			close(iofile[1]);
		iofile[0] = pipefd[0];
		job->process = job->process->next;
	}
	job->process = process;
}

void			exec_job(t_shell *sh, t_job *job)
{
	t_job 	*tmp;

	tmp = job;
	while (job)
	{
		launch_process(sh, job);
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
	job = tmp;
	free_job(job);
}

void			parse_cmd(t_shell *sh, t_token *token)
{
	t_job		*job;
	t_process	*process;

	job = NULL;
	process = NULL;
	while (token)
	{
		if (token->token_value == PIPE)
		{
			token_pipe(sh, &process, token);
			token = token->next;
		}
		else if (token->token_value == AND || token->token_value == OR ||
				token->token_value == SEPARATOR)
		{
			token_linker(sh, &job, &process, token);
			token = token->next;
		}
		else
		{
			if ((token = hub_redir(sh, token)) == NULL)
				return ;
		}
	}
	exec_job(sh, job);
}
