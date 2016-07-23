/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:57:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/23 17:07:38 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_dlist	*create_node(void)
{
	t_dlist	*node;

	if (!(node = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	node->str = ft_strdup("");
	node->i = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_node_bis(t_dlist **head, t_dlist *new_node)
{
	t_dlist *cur;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
}

void	go_to_end_list(t_struct *info)
{
	char	*str;

	str = ft_strdup(info->node->str);
	while (info->node->next)
		info->node = info->node->next;
	info->node->str = ft_strdup(str);
}
