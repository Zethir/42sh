/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:35:47 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/03 19:26:55 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	free_job(t_job *job)
{
	t_job		*tmp;
	t_process	*tmp2;

	while (job)
	{
		while (job->process)
		{
			if (job->process->cmd)
				free(job->process->cmd);
			job->process->completed = 0;
			tmp2 = job->process;
			job->process = job->process->next;
			free(tmp2);
		}
		free(job->process);
		job->process = NULL;
		job->linker = 0;
		tmp = job;
		job = job->next;
		free(tmp);
	}
	free(job);
	job = NULL;
}

void	free_parse(t_parse **head)
{
	t_parse *parse;

	parse = *head;
	if (parse->argv)
		ft_free_tab(parse->argv);
	if (parse->env)
		ft_free_tab(parse->env);
	if (parse->right_path)
		free(parse->right_path);
	parse->pid = 0;
	free(parse);
	parse = NULL;
}
