/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:45:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/08 17:36:12 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int	is_replace(t_lex *lex, char *str, int i)
{
	if (ft_isdigit(lex->line[i - 1]))
		str = ft_strjoin(ft_chardup(lex->line[i - 1]), str);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		str = ft_strjoin(str, "&-");
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
				str, 7);
		return (i + 2);
	}
	if (lex->line[i] == '&')
		return (is_replace_bis(lex, str, i));
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		i++;
	}
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
			str, 6);
	return (i);
}

static int	is_in(t_lex *lex, char *str, int i)
{
	if (ft_isdigit(lex->line[i - 1]))
		str = ft_strjoin(ft_chardup(lex->line[i - 1]), str);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		str = ft_strjoin(str, "&-");
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
				str, 11);
		return (i + 2);
	}
	if (lex->line[i] == '&')
		return (is_in_bis(lex, str, i));
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		i++;
	}
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
			str, 10);
	return (i);
}

static int	is_add(t_lex *lex, char *str, int i)
{
	if (ft_isdigit(lex->line[i - 1]))
		str = ft_strjoin(ft_chardup(lex->line[i - 1]), str);
	i += 2;
	if (lex->line[i] == '<' || lex->line[i] == '|' || lex->line[i] == ';' ||
			lex->line[i] == '>')
		return (-1);
	if (lex->line[i] == '&')
		return (is_add_bis(lex, str, i));
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		i++;
	}
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
			str, 4);
	return (i);
}

static int	is_heredoc(t_lex *lex, char *str, int i)
{
	if (ft_isdigit(lex->line[i - 1]))
		str = ft_strjoin(ft_chardup(lex->line[i - 1]), str);
	i += 2;
	if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '|' ||
			lex->line[i] == '&' || lex->line[i] == ';')
		return (-1);
	add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
			str, 9);
	return (i);
}

int			is_redir(t_lex *lex, int i)
{
	char	*str;

	if (lex->line[i] == '>' && lex->line[i + 1] == '>')
	{
		str = ft_strdup(">>");
		i = is_add(lex, str, i);
	}
	else if (lex->line[i] == '<' && lex->line[i + 1] == '<')
	{
		str = ft_strdup("<<");
		i = is_heredoc(lex, str, i);
	}
	else if (lex->line[i] == '<' && lex->line[i - 1] != '<')
	{
		str = ft_strdup("<");
		i = is_in(lex, str, i);
	}
	else if (lex->line[i] == '>' && lex->line[i - 1] != '>')
	{
		str = ft_strdup(">");
		i = is_replace(lex, str, i);
	}
	else
		return (0);
	return (i);
}
