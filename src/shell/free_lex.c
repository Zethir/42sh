/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:25:59 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/26 17:58:34 by cboussau         ###   ########.fr       */
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
	lex->fd[0] = 0;
	lex->fd[1] = 0;
	free(lex);
	lex = NULL;
}

void	free_token_ht(t_token_ht **token)
{
	t_token_ht	*token_ht;

	token_ht = *token;
	free(token_ht);
	token_ht = NULL;
}
