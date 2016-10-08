/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/08 17:29:41 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		push_token(t_process *node, t_process **head)
{
	t_process		*tmp;
	t_process		*tmp2;

	tmp2 = *head;
	if (tmp2->name == NULL)
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

void			add_token(t_lex *lex, char *cmd, char *new_token, int val)
{
	t_process		*new_elem;
	
	if (!(new_elem = (t_process *)malloc(sizeof(t_process))))
		return ;
	new_elem->next = NULL;
	new_elem->cmd = ft_strdup(cmd);
	new_elem->token = ft_strdup(token);
	new_elem->token_value = val;
	token->stdio[0] = 0;
	token->stdio[1] = 1;
	token->stdio[2] = 2;
	push_token(new_elem, &lex->token);
}

t_process		*init_process_struct(void)
{
	t_process *token;

	token = (t_process *)malloc(sizeof(t_process));
	token->next = NULL;
	token->cmd = NULL;
	token->token = NULL;
	token->stdio[0] = 0;
	token->stdio[1] = 0;
	token->stdio[2] = 0;
	token->token_value = 0;
	return (token);
}
