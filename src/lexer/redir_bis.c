/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:17:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/27 17:27:31 by cboussau         ###   ########.fr       */
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
		i++;
	}
	add_token(lex->token, str, 9);
	return (i);
}

int		is_in_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		i++;
	}
	add_token(lex->token, str, 15);
	return (i);
}

int		is_add_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		i++;
	}
	add_token(lex->token, str, 6);
	return (i);
}

int		is_heredoc_bis(t_lex *lex, char *str, int i)
{
	i++;
	str = ft_strjoin(str, "&");
	if (ft_isdigit(lex->line[i]))
	{
		str = ft_strjoin(str, ft_chardup(lex->line[i]));
		i++;
	}
	add_token(lex->token, str, 12);
	return (i);
}
