/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/01 16:02:51 by cboussau         ###   ########.fr       */
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

void	free_struct_lex(t_lex *lex)
{
	while (lex->cmd)
	{
		if (lex->cmd->argv)
			ft_strdel(lex->cmd->argv);
		lex->cmd->index = 0;
		lex->cmd = lex->cmd->next;
	}
	free(lex->cmd);
	lex->cmd = NULL;
	while (lex->token)
	{
		if (lex->token->name)
			ft_strdel(&lex->token->name);
		lex->token->value = 0;
		lex->token = lex->token->next;
	}
	free(lex->token);
	lex->token = NULL;
}

void	free_lex(t_lex *lex)
{
	ft_strdel(&lex->line);
	ft_strdel(lex->arg);
	lex->hd = 0;
	lex->tl = 0;
	free(lex);
	lex = NULL;
}

void	free_parse(t_parse *parse)
{
	ft_strdel(parse->right_path);
	ft_strdel(parse->env);
	ft_strdel(&parse->bin_path);
	parse->pid = 0;
	parse->bl = 0;
	free(parse);
	parse = NULL;
}
