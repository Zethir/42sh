/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:17:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/28 13:56:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int		is_replace_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		add_token(lex->token, str, 9);
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
		add_token(lex->token, str, 15);
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
		add_token(lex->token, str, 6);
		i++;
		return (i);
	}
	else
		return (-1);
}

int		is_heredoc_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		add_token(lex->token, str, 12);
		i++;
		return (i);
	}
	else
		return (-1);
}
