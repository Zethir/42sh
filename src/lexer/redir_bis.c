/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:17:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/03 20:21:10 by cboussau         ###   ########.fr       */
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
		add_token(lex, str, 7);
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
		add_token(lex, str, 11);
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
		add_token(lex, str, 6);
		i++;
		return (i);
	}
	else
		return (-1);
}
