/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:57:33 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/24 14:58:39 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

static int		is_and(char *line)
{
	if (*line == '&' && *(line + 1) == '&' && *(line - 1) != '&')
		return (1);
	return (0);
}

static int		is_or(char *line)
{
	if (*line == '|' && *(line + 1) == '|')
		return (2);
	return (0);
}

static int		is_pipe(char *line)
{
	if (*line == '|' && *(line - 1) != '|')
		return (3);
	return (0);
}

void			is_token(t_lex *lex)
{
	while (*lex->line)
	{
		if ((is_and(lex->line)))
			add_token(lex->token, "&&", 1);
		else if ((is_or(lex->line)))
			add_token(lex->token, "||", 2);
		else if ((is_pipe(lex->line)))
			add_token(lex->token, "|", 3);
		else 
			is_redir(lex);
		lex->line++;
	}
}
