/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:07:18 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/11 18:49:18 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	free_job(t_job *job)
{
	while (job)
	{
		if (job->linker == 0)
			job = job->next;
		while (job->process)
		{
			if (job->process->cmd)
				ft_strdel(&job->process->cmd);
			if (job->process->stdio)
				free(job->process->stdio);
			job->process->completed = 0;
			job->process = job->process->next;
		}
		free(job->process);
		job->process = NULL;
		job->linker = 0;
		job = job->next;
	}
	free(job);
	job = NULL;
}