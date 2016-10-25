/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:25:59 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/25 19:08:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void	free_struct_lex(t_lex **head)
{
	t_token	*tmp;
	t_lex	*lex;

	lex = *head;
	if (lex->line)
	{
		while (lex->token)
		{
			if (lex->token->cmd)
				free(lex->token->cmd);
			if (lex->token->fd)
				free(lex->token->fd);
			lex->token->token_value = 0;
			tmp = lex->token;
			lex->token = lex->token->next;
			free(tmp);
		}
		free(lex->token);
		lex->token = NULL;
	}
}

void	free_lex(t_lex **head)
{
	t_lex	*lex;

	lex = *head;
	free_struct_lex(&lex);
	if (lex->line)
		free(lex->line);
	lex->hd = 0;
	lex->tl = 0;
	if (lex->fd)
		free(lex->fd);
	free(lex);
	lex = NULL;
}
