/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:17:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/08 17:37:00 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		is_replace_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
				str, 8);
		i++;
		return (i);
	}
	else
		return (-1);
}

int		is_in_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
				str, 12);
		i++;
		return (i);
	}
	else
		return (-1);
}

int		is_add_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl),
				str, 5);
		i++;
		return (i);
	}
	else
		return (-1);
}
