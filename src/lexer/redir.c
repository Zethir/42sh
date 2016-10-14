/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:45:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/14 19:49:16 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int	is_replace(t_lex *lex, int i)
{
	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 7);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 8);
		return (i);
	}
	i = get_second_fd(lex, i);
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 6);
	return (i);
}

static int	is_in(t_lex *lex, int i)
{
	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 11);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 12);
		return (i);
	}
	i = get_second_fd(lex, i);
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 10);
	return (i);
}

static int	is_add(t_lex *lex, int i)
{
	get_first_fd(lex, i);
	i += 2;
	if (lex->line[i] == '<' || lex->line[i] == '|' || lex->line[i] == ';' ||
			lex->line[i] == '>')
		return (-1);
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 5);
		return (i);
	}
	i = get_second_fd(lex, i);
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 4);
	return (i);
}

static int	is_heredoc(t_lex *lex, int i)
{
	i += 2;
	if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '|' ||
			lex->line[i] == '&' || lex->line[i] == ';')
		return (-1);
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), 9);
	return (i);
}

int			is_redir(t_lex *lex, int i)
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
	if (lex->fd[0] != -1 || lex->fd[1] != -1)
	{
		lex->fd[0] = -1;
		lex->fd[0] = -1;
	}
	return (i);
}
