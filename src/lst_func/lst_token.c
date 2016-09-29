/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/29 14:21:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static void		push_token(t_token *node, t_token **head)
{
	t_token		*tmp;
	t_token		*tmp2;

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

void			add_token(t_lex *lex, char *new_token, int val)
{
	t_token		*new_elem;
	
	if (!(new_elem = (t_token *)malloc(sizeof(t_token))))
		return ;
	new_elem->next = NULL;
	new_elem->name = ft_strdup(new_token);
	new_elem->value = val;
	push_token(new_elem, &lex->token);
}
