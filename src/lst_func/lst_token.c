/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/28 12:30:39 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

static void		push_token(t_token *node, t_token **head)
{
	t_token		*tmp;

	if (*head == NULL)
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

void			add_token(t_token *t, char *new_token, int val)
{
	t_token		*new_elem;

	if (!(new_elem = (t_token *)malloc(sizeof(t_token))))
		return ;
	new_elem->next = NULL;
	new_elem->name = ft_strdup(new_token);
	new_elem->value = val;
	push_token(new_elem, &t);
}
