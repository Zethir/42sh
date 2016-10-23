/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/23 10:09:10 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	free_list(t_lst *node)
{
	while (node)
	{
		if (node->line)
			free(node->line);
		if (node->name)
			free(node->name);
		node = node->next;
	}
	free(node);
	node = NULL;
}

void	free_dlist(t_dlist *node)
{
	while (node)
	{
		if (node->str)
			free(node->str);
		node = node->next;
	}
	free(node);
	node = NULL;
}

void	free_struct_lex(t_lex **head)
{
	t_lex	*lex;

	lex = *head;
	if (lex->line)
	{
		while (lex->token)
		{
			if (lex->token->cmd)
				ft_strdel(&lex->token->cmd);
			if (lex->token->fd)
				free(lex->token->fd);
			lex->token->token_value = 0;
			lex->token = lex->token->next;
		}
		free(lex->token);
		lex->token = NULL;
	}
}

void	free_lex(t_lex **head)
{
	t_lex	*lex;

	lex = *head;
	if (lex->line)
		ft_strdel(&lex->line);
	lex->hd = 0;
	lex->tl = 0;
	if (lex->fd)
		free(lex->fd);
	free(lex);
	lex = NULL;
}
