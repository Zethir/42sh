/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hub_job.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:35:47 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 17:05:07 by cboussau         ###   ########.fr       */
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

void	free_hub(t_hub *info)
{
	while (info->node)
	{
		if (info->node->str)
			ft_strdel(&info->node->str);
		info->node = info->node->next;
	}
	free(info->node);
	info->node = NULL;
	if (info->stdio)
		free(info->stdio);
	free(info);
	info = NULL;
}

void	free_prompt(t_prompt **prompt)
{
	t_prompt *tmp;

	tmp = *prompt;
	if (tmp->cmd)
		free(tmp->cmd);
	tmp->i = 0;
	tmp->copy_mode = 0;
	tmp->cursor_start = 0;
	tmp->cursor_end = 0;
	if (tmp->copy_str)
		free(tmp->copy_str);
	tmp->win_size = 0;
	free(tmp);
	tmp = NULL;
}
