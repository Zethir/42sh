/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:45:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/26 16:38:22 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int	is_replace(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		if ((token_ht = add_token(lex, token_ht, tmp, 7)) == NULL)
			return (-1);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		if ((token_ht = add_token(lex, token_ht, tmp, 8)) == NULL)
			return (-1);
		return (i);
	}
	if ((token_ht = add_token(lex, token_ht, tmp, 6)) == NULL)
		return (-1);
	return (i);
}

static int	is_in(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	if (lex->line[i] == '&' && lex->line[i + 1] == '-')
	{
		if ((token_ht = add_token(lex, token_ht, tmp, 11)) == NULL)
			return (-1);
		return (i + 2);
	}
	if (lex->line[i] == '&')
	{
		i = get_second_fd(lex, i + 1);
		if ((token_ht = add_token(lex, token_ht, tmp, 12)) == NULL)
			return (-1);
		return (i);
	}
	if ((token_ht = add_token(lex, token_ht, tmp, 10)) == NULL)
		return (-1);
	return (i);
}

static int	is_add(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	get_first_fd(lex, i);
	i += 2;
	if (lex->line[i] == '<' || lex->line[i] == '|' || lex->line[i] == ';' ||
			lex->line[i] == '>' || lex->line[i] == '&')
		return (-1);
	if ((token_ht = add_token(lex, token_ht, tmp, 4)) == NULL)
		return (-1);
	return (i);
}

static int	is_heredoc(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	i += 2;
	if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '|' ||
			lex->line[i] == '&' || lex->line[i] == ';')
		return (-1);
	if ((token_ht = add_token(lex, token_ht, tmp, 9)) == NULL)
		return (-1);
	return (i);
}

int			is_redir(t_lex *lex, t_token_ht *token_ht, int i, char *tmp)
{
	if (lex->line[i] == '>' && lex->line[i + 1] == '>')
		i = is_add(lex, token_ht, i, tmp);
	else if (lex->line[i] == '<' && lex->line[i + 1] == '<')
		i = is_heredoc(lex, token_ht, i, tmp);
	else if (lex->line[i] == '<' && lex->line[i - 1] != '<')
		i = is_in(lex, token_ht, i, tmp);
	else if (lex->line[i] == '>' && lex->line[i - 1] != '>')
		i = is_replace(lex, token_ht, i, tmp);
	else
		return (0);
	if (lex->fd[0] != -1 || lex->fd[1] != -1)
	{
		lex->fd[0] = -1;
		lex->fd[0] = -1;
	}
	return (i);
}
