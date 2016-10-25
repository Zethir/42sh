/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:57:33 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/25 16:10:18 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int		is_and(t_lex *lex, int i, char *tmp)
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
					lex->line[i] == '<' || lex->line[i] == ';')
				return (-1);
			if (add_token(lex, tmp, 1) < 0)
				return (-1);
			return (i);
		}
	}
	return (0);
}

static int		is_or(t_lex *lex, int i, char *tmp)
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
			if (add_token(lex, tmp, 2) < 0)
				return (-1);
			return (i);
		}
		if (add_token(lex, tmp,	3) < 0)
			return (-1);
		return (i);
	}
	return (0);
}

static int		is_separator(t_lex *lex, int i, char *tmp)
{
	if (lex->line[i] == ';')
	{
		i++;
		if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '&'
				|| lex->line[i] == '|')
			return (-1);
		if (add_token(lex, tmp,	13) < 0)
			return (-1);
		return (i);
	}
	return (0);
}

int				is_token(t_lex *lex, int i)
{
	char	*tmp;
	int		j;

	tmp = ft_strsub(lex->line, lex->tl, lex->hd - lex->tl);
	j = is_and(lex, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	j = is_or(lex, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	j = is_redir(lex, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	j = is_separator(lex, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	free(tmp);
	return (j);
}
