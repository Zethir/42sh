/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:22:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/09 18:38:58 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	push_process(t_process *node, t_process **head)
{
	t_process	*tmp;
	t_process	*tmp2;

	tmp2 = *head;
	if (tmp2->cmd == NULL)
	{
		*head = node;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	create_process(t_job *job, t_token *token, int stdio[3])
{
	t_process	*new_elem;

	if (!(new_elem = (t_process *)malloc(sizeof(t_process))))
		return ;
	new_elem->next = NULL;
	new_elem->stdio[0] = stdio[0];
	new_elem->stdio[1] = stdio[1];
	new_elem->stdio[2] = stdio[2];
	new_elem->cmd = ft_strdup(token->cmd);
	push_process(new_elem, &job->process);
}

void	push_job(t_job *node, t_job **head)
{
	t_job	*tmp;
	t_job	*tmp2;

	tmp2 = *head;
	if (tmp2->linker == 0)
	{
		*head = node;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	create_job(t_job *job, t_token *token)
{
	t_job	*new_job;

	if (!(new_job = (t_job *)malloc(sizeof(t_job))))
		return ;
	new_job->process = job->process;
	new_job->linker = token->token_value;
	push_job(new_job, &job);
}

t_job		*init_job(void)
{
	t_job	*job;

	if (!(job = (t_job *)malloc(sizeof(t_job))))
		return (NULL);
	job->linker = 0;
	if (!(job->process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	job->process->cmd = NULL;
	job->process->stdio[0] = 0;
	job->process->stdio[1] = 1;
	job->process->stdio[2] = 2;
	job->next = NULL;
	return (job);
}
