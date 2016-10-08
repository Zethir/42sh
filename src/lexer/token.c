/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:57:33 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/08 17:47:07 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int		is_and(t_lex *lex, int i)
{
	if (lex->line[i] == '&')
	{
		i++;
		if (lex->line[i] == '|' || lex->line[i] == '<' || lex->line[i] == '>'
				|| lex->line[i] == ';')
			return (-1);
		else if (lex->line[i] == '&')
		{
			i++;
			if (lex->line[i] == '|' || lex->line[i] == '&' ||
					lex->line[i] == '<' || lex->line[i] == ';' )
				return (-1);
			add_process(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), "&&", 1);
			return (i);
		}
	}
	return (0);
}

static int		is_or(t_lex *lex, int i)
{
	if (lex->line[i] == '|')
	{
		i++;
		if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '&'
				|| lex->line[i] == ';')
			return (-1);
		else if (lex->line[i] == '|')
		{
			i++;
			if (lex->line[i] == '>' || lex->line[i] == '<' ||
					lex->line[i] == '&' || lex->line[i] == '|' ||
					lex->line[i] == ';')
				return (-1);
			add_process(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), "||", 2);
			return (i);
		}
		add_process(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), "|", 3);
		return (i);
	}
	return (0);
}

static int		is_separator(t_lex *lex, int i)
{
	if (lex->line[i] == ';')
	{
		i++;
		if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '&'
				|| lex->line[i] == '|')
			return (-1);
		add_process(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), ";", 13);
		return (i);
	}
	return (0);
}

int				is_token(t_lex *lex, int i)
{
	int		j;

	j = is_and(lex, i);
	if (j > 0 || j < 0)
		return (j);
	j = is_or(lex, i);
	if (j > 0 || j < 0)
		return (j);
	j = is_redir(lex, i);
	if (j > 0 || j < 0)
		return (j);
	j = is_separator(lex, i);
	if (j > 0 || j < 0)
		return (j);
	return (j);
}
