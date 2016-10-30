/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 14:31:11 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/29 14:35:42 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int		is_replace_bis(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		if ((token_ht = add_token(lex, token_ht, tmp, 7)) == NULL)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		if ((token_ht = add_token(lex, token_ht, tmp, 8)) == NULL)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		return (i);
	}
	return (i);
}

int		is_in_bis(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		if ((token_ht = add_token(lex, token_ht, tmp, 11)) == NULL)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		if ((token_ht = add_token(lex, token_ht, tmp, 12)) == NULL)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		return (i);
	}
	return (i);
}
