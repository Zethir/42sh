/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:57:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 18:17:04 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

t_dlist	*create_node(void)
{
	t_dlist	*node;

	if (!(node = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	node->str = ft_strdup("");
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

void	go_to_end_list(t_hub *info)
{
	char	*str;

	str = ft_strdup(info->node->str);
	while (info->node->next)
		info->node = info->node->next;
	info->node->str = ft_strdup(str);
	free(str);
}

t_lex	*init_lexer_struct(void)
{
	t_lex	*lex;

	if (!(lex = (t_lex *)malloc(sizeof(t_lex))))
		return (NULL);
	if (!(lex->fd = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	lex->line = ft_strdup("");
	lex->hd = 0;
	lex->tl = 0;
	lex->fd[0] = -1;
	lex->fd[1] = -1;
	return (lex);
}
