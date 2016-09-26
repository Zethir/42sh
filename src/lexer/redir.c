/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:45:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/26 16:19:03 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int		is_replace(t_lex *lex, int i)
{
	i++;
	if (lex->line[i] == '|')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		add_token(lex->token, ">&-", 8);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i++;
		while (ft_isdigit(lex->line[i]))
			i++;
		add_token(lex->token, ">&", 9);
		return (i);
	}
	add_token(lex->token, ">", 7);
	return (i);
}

static int		is_in(t_lex *lex, int i)
{
	i++;
	if (lex->line[i] == '|')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		add_token(lex->token, "<&-", 14);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i++;
		while (ft_isdigit(lex->line[i]))
			i++;
		add_token(lex->token, "<&", 15);
		return (i);
	}
	add_token(lex->token, "<", 13);
	return (i);
}

static int		is_add(t_lex *lex, int i)
{
	i += 2;
	if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '|')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		add_token(lex->token, ">>&-", 5);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i++;
		while (ft_isdigit(lex->line[i]))
			i++;
		add_token(lex->token, ">>&", 6);
		return (i);
	}
	add_token(lex->token, ">>", 4);
	return (i);
}

static int		is_heredoc(t_lex *lex, int i)
{
	i += 2;
	if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '|')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		add_token(lex->token, "<<&-", 11);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i++;
		while (ft_isdigit(lex->line[i]))
			i++;
		add_token(lex->token, "<<&", 12);
		return (i);
	}
	add_token(lex->token, "<<", 10);
	return (i);
}

int				is_redir(t_lex *lex, int i)
{
	if (lex->line[i] == '>' && lex->line[i + 1] == '>')
		i = is_add(lex, i);
	else if (lex->line[i] == '<' && lex->line[i + 1] == '<')
		i = is_heredoc(lex, i);
	else if (lex->line[i] == '<' && lex->line[i - 1] != '<')
		i = is_in(lex, i);
	else if (lex->line[i] == '>' && lex->line[i - 1] != '>')
		i = is_replace(lex, i);
	else
		return (0);
	return (i);
}
