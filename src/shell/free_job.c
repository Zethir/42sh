/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 15:35:47 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/25 14:26:12 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	free_job(t_job *job)
{
	t_job		*tmp;
	t_process	*tmp2;

	while (job)
	{
		if (job->linker == 0)
			job = job->next;
		while (job->process)
		{
			if (job->process->cmd)
				free(job->process->cmd);
			if (job->process->stdio)
				free(job->process->stdio);
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
	int		i;

	parse = *head;
	i = 0;
	while (parse->argv[i])
	{
		if (parse->argv[i])
			free(parse->argv[i]);
		i++;
	}
	free(parse->argv);
	i = 0;
	while (parse->env[i])
	{
		if (parse->env[i])
			free(parse->env[i]);
		i++;
	}
	free(parse->env);
	if (parse->right_path)
		free(parse->right_path);
	parse->pid = 0;
	free(parse);
	parse = NULL;
}