/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 16:49:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	free_list(t_lst *node)
{
	while (node)
	{
		if (node->line)
			ft_strdel(&node->line);
		if (node->name)
			ft_strdel(&node->name);
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
			ft_strdel(&node->str);
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
	ft_strdel(&lex->line);
	lex->hd = 0;
	lex->tl = 0;
	free(lex);
	lex = NULL;
}

void	free_parse(t_parse *parse)
{
	if (parse->right_path)
		ft_strdel(&parse->right_path);
	if (parse->env)
		ft_strdel(parse->env);
	if (parse->argv)
		ft_strdel(parse->argv);
	parse->pid = 0;
	free(parse);
	parse = NULL;
}
