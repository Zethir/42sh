/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 12:56:15 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/10 18:10:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int		job_success(t_job *job)
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

int		get_num_process(t_process *process)
{
	t_process	*tmp;
	int			i;

	i = 0;
	tmp = process;
	while (process)
	{
		i++;
		process = process->next;
	}
	process = tmp;
	return (i);
}

void	update_process_status(t_shell *sh, t_process *p, pid_t pid, int status)
{
	t_process *tmp;

	tmp = p;
	while (p)
	{
		if (p->pid == pid)
		{
			if (WIFEXITED(status) && status == 0)
			{
				p->completed = 1;
				sh->return_val = WEXITSTATUS(status);
			}
			if (WIFEXITED(status) && status != 0)
			{
				p->completed = 0;
				sh->return_val = WEXITSTATUS(status);
			}
			if (WIFSIGNALED(status))
			{
				p->completed = 1;
				sh->return_val = WEXITSTATUS(status);
			}
		}
		p = p->next;
	}
	p = tmp;
}

void	wait_for_job(t_shell *sh, t_job *job, int i)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = 0;
	while (i > 0)
	{
		pid = wait(&status);
		update_process_status(sh, job->process, pid, status);
		if (pid == -1)
			break ;
		status = 0;
		i--;
	}
}
