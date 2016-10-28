/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:57:33 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/28 14:45:52 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int		is_and(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
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
			if ((token_ht = add_token(lex, token_ht, tmp, 1)) == NULL)
				return (-1);
			return (i);
		}
	}
	return (0);
}

static int		is_or(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
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
			if ((token_ht = add_token(lex, token_ht, tmp, 2)) == NULL)
				return (-1);
			return (i);
		}
		if ((token_ht = add_token(lex, token_ht, tmp, 3)) == NULL)
			return (-1);
		return (i);
	}
	return (0);
}

static int		is_separator(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	if (lex->line[i] == ';')
	{
		i++;
		if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '&'
				|| lex->line[i] == '|')
			return (-1);
		if ((token_ht = add_token(lex, token_ht, tmp, 13)) == NULL)
			return (-1);
		return (i);
	}
	return (0);
}

static int		is_token_bis(t_lex *lex, t_token_ht *token_ht, int i)
{
	char	*tmp;
	int		j;

	tmp = ft_strsub(lex->line, lex->tl, lex->hd - lex->tl);
	j = is_redir(lex, token_ht, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	j = is_separator(lex, token_ht, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	free(tmp);
	return (j);
}

int				is_token(t_lex *lex, t_token_ht *token_ht, int i)
{
	char	*tmp;
	int		j;

	tmp = ft_strsub(lex->line, lex->tl, lex->hd - lex->tl);
	j = is_and(lex, token_ht, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	j = is_or(lex, token_ht, i, tmp);
	if (j > 0 || j < 0)
	{
		free(tmp);
		return (j);
	}
	j = is_token_bis(lex, token_ht, i);
	free(tmp);
	return (j);
}
