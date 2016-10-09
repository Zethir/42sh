/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/09 17:09:42 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		push_token(t_token *node, t_token **head)
{
	t_token		*tmp;
	t_token		*tmp2;

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

void			add_token(t_lex *lex, char *cmd, char *new_token, int val)
{
	t_token		*new_elem;
	
	if (!(new_elem = (t_token *)malloc(sizeof(t_token))))
		return ;
	new_elem->next = NULL;
	new_elem->cmd = ft_strdup(cmd);
	new_elem->token = ft_strdup(new_token);
	new_elem->token_value = val;
	push_token(new_elem, &lex->token);
}

t_token		*init_token_struct(void)
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	token->next = NULL;
	token->cmd = NULL;
	token->token = NULL;
	token->token_value = 0;
	return (token);
}
