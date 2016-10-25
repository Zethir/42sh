/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:45:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/25 16:13:13 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int	is_replace(t_lex *lex, int i, char *tmp)
{
	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		if (add_token(lex, tmp, 7) < 0)
			return (-1);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		if (add_token(lex, tmp, 8) < 0)
			return (-1);
		return (i);
	}
	if (add_token(lex, tmp, 6) < 0)
		return (-1);
	return (i);
}

static int	is_in(t_lex *lex, int i, char *tmp)
{
	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		if (add_token(lex, tmp, 11)	< 0)
			return (-1);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		if (add_token(lex, tmp, 12)	< 0)
			return (-1);
		return (i);
	}
	if (add_token(lex, tmp, 10)	< 0)
		return (-1);
	return (i);
}

static int	is_add(t_lex *lex, int i, char *tmp)
{
	get_first_fd(lex, i);
	i += 2;
	if (lex->line[i] == '<' || lex->line[i] == '|' || lex->line[i] == ';' ||
			lex->line[i] == '>' || lex->line[i] == '&')
		return (-1);
	if (add_token(lex, tmp, 4) < 0)
		return (-1);
	return (i);
}

static int	is_heredoc(t_lex *lex, int i, char *tmp)
{
	i += 2;
	if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '|' ||
			lex->line[i] == '&' || lex->line[i] == ';')
		return (-1);
	if (add_token(lex, tmp, 9) < 0)
		return (-1);
	return (i);
}

int			is_redir(t_lex *lex, int i, char *tmp)
{
	if (lex->line[i] == '>' && lex->line[i + 1] == '>')
		i = is_add(lex, i, tmp);
	else if (lex->line[i] == '<' && lex->line[i + 1] == '<')
		i = is_heredoc(lex, i, tmp);
	else if (lex->line[i] == '<' && lex->line[i - 1] != '<')
		i = is_in(lex, i, tmp);
	else if (lex->line[i] == '>' && lex->line[i - 1] != '>')
		i = is_replace(lex, i, tmp);
	else
		return (0);
	if (lex->fd[0] != -1 || lex->fd[1] != -1)
	{
		lex->fd[0] = -1;
		lex->fd[0] = -1;
	}
	return (i);
}
