/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:57:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/27 16:42:46 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

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

void	go_to_end_list(t_env_hist *info)
{
	char	*str;

	str = ft_strdup(info->node->str);
	while (info->node->next)
		info->node = info->node->next;
	info->node->str = ft_strdup(str);
}

t_lex	*init_lexer_struct(void)
{
	t_lex	*lex;

	lex = (t_lex *)malloc(sizeof(t_lex));
	lex->line = ft_strdup("");
	lex->arg = NULL;
	lex->token = (t_token *)malloc(sizeof(t_token));
	lex->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	lex->token->next = NULL;
	lex->cmd->next = NULL;
	lex->cmd->str = ft_strdup("");
	lex->cmd->index = 0;
	lex->token->name = NULL;
	lex->token->value = 0;
	lex->hd = 0;
	lex->tl = 0;
	return (lex);
}
