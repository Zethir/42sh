/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/08 17:46:27 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		push_token(t_process *node, t_process **head)
{
	t_process		*tmp;
	t_process		*tmp2;

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

void			add_process(t_lex *lex, char *cmd, char *new_token, int val)
{
	t_process		*new_elem;
	
	if (!(new_elem = (t_process *)malloc(sizeof(t_process))))
		return ;
	new_elem->next = NULL;
	new_elem->cmd = ft_strdup(cmd);
	new_elem->token = ft_strdup(new_token);
	new_elem->token_value = val;
	new_elem->stdio[0] = 0;
	new_elem->stdio[1] = 1;
	new_elem->stdio[2] = 2;
	push_token(new_elem, &lex->process);
}

t_process		*init_process_struct(void)
{
	t_process *process;

	process = (t_process *)malloc(sizeof(t_process));
	process->next = NULL;
	process->cmd = NULL;
	process->token = NULL;
	process->stdio[0] = 0;
	process->stdio[1] = 0;
	process->stdio[2] = 0;
	process->token_value = 0;
	return (process);
}
