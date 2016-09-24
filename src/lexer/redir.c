/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:45:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/22 17:20:36 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

static void		is_replace(t_lex *lex)
{
	if (*lex->line == '>' && *(lex->line - 1) != '>' &&
			*(lex->line - 1) != '1' && *(lex->line - 1) != '&' &&
			*(lex->line - 1) != '2' && *(lex->line + 1) != '&')
		add_token(lex->token, ">", 12);
	else if (*lex->line == '>' && *(lex->line - 1) == '1')
		add_token(lex->token, "1>", 13);
	else if (*lex->line == '>' && *(lex->line - 1) == '&')
		add_token(lex->token, "&>", 14);
	else if (*lex->line == '>' && *(lex->line - 1) == '2' &&
			*(lex->line + 1) != '&')
		add_token(lex->token, "2>", 15);
	else if (*lex->line == '>' && *(lex->line - 1) != '>' &&
			*(lex->line - 1) != '1' && *(lex->line - 1) != '2' &&
			*(lex->line - 1) != '&' && *(lex->line + 1) == '&' &&
			*(lex->line + 2) != '-')
		add_token(lex->token, ">&", 16);
	else if (*lex->line == '>' && *(lex->line - 1) == '2' &&
			*(lex->line + 1) == '&')
		add_token(lex->token, "2>&", 17);
	else if (*lex->line == '>' && *(lex->line - 1) != '>' &&
			*(lex->line - 1) != '1' && *(lex->line - 1) != '2' &&
			*(lex->line - 1) != '&' && *(lex->line + 1) == '&')
		add_token(lex->token, ">&-", 18);
	else
		return ;
}

static void		is_in(t_lex *lex)
{
	if (*lex->line == '<' && *(lex->line - 1) != '<' &&
			*(lex->line + 1) != '1' && *(lex->line + 1) != '&')
		add_token(lex->token, "<", 9);
	else if (*lex->line == '<' && *(lex->line + 1) == '1' &&
			*(lex->line - 1) != '<')
		add_token(lex->token, "<1", 10);
	else if (*lex->line == '<' && *(lex->line + 1) == '&' &&
			*(lex->line - 1) != '<')
		add_token(lex->token, "<&", 11);
}

static void		is_add(t_lex *lex)
{
	if (*lex->line == '>' && *(lex->line + 1) == '>' &&
			(*(lex->line - 1) != '1' && *(lex->line - 1) != '2'))
		add_token(lex->token, ">>", 4);
	else if (*lex->line == '>' && *(lex->line + 1) == '>' &&
			*(lex->line - 1) == '1')
		add_token(lex->token, "1>>", 5);
	else if (*lex->line == '>' && *(lex->line + 1) == '>' &&
			*(lex->line - 1) == '2')
		add_token(lex->token, "2>>", 6);
	else
		return ;
}

static void		is_heredoc(t_lex *lex)
{
	if (*lex->line == '<' && *(lex->line + 1) == '<' &&
			*(lex->line + 2) != '1')
		add_token(lex->token, "<<", 7);
	else if (*lex->line == '<' && *(lex->line + 1) == '<' &&
			*(lex->line + 2) == '1')
		add_token(lex->token, "<<1", 8);
	else
		return ;
}

void			is_redir(t_lex *lex)
{
	if (*lex->line == '>' && *(lex->line + 1) == '>')
		is_add(lex);
	else if (*lex->line == '<' && *(lex->line + 1) == '<')
		is_heredoc(lex);
	else if (*lex->line == '<' && *(lex->line - 1) != '<')
		is_in(lex);
	else if (*lex->line == '>' && *(lex->line - 1) != '>')
		is_replace(lex);
	else
		return ;
}
