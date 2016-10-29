/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:45:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/29 14:42:27 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int	is_replace(t_lex *lex, t_token_ht *token_ht, int i)
{
	char	*tmp;
	int		j;

	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	tmp = ft_strsub(lex->line, lex->tl, lex->hd - lex->tl);
	j = is_replace_bis(lex, token_ht, i, tmp);
	if (j != i)
		return (j);
	if ((token_ht = add_token(lex, token_ht, tmp, 6)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (i);
}

static int	is_in(t_lex *lex, t_token_ht *token_ht, int i)
{
	char	*tmp;
	int		j;

	get_first_fd(lex, i);
	i++;
	if (lex->line[i] == '|' || lex->line[i] == ';')
		return (-1);
	tmp = ft_strsub(lex->line, lex->tl, lex->hd - lex->tl);
	j = is_replace_bis(lex, token_ht, i, tmp);
	if (j != i)
		return (j);
	if ((token_ht = add_token(lex, token_ht, tmp, 10)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (i);
}

static int	is_add(t_lex *lex, t_token_ht *token_ht, int i)
{
	char	*tmp;

	get_first_fd(lex, i);
	i += 2;
	if (lex->line[i] == '<' || lex->line[i] == '|' || lex->line[i] == ';' ||
			lex->line[i] == '>' || lex->line[i] == '&')
		return (-1);
	tmp = ft_strsub(lex->line, lex->tl, lex->hd - lex->tl);
	if ((token_ht = add_token(lex, token_ht, tmp, 4)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (i);
}

static int	is_heredoc(t_lex *lex, t_token_ht *token_ht, int i)
{
	char	*tmp;

	i += 2;
	if (lex->line[i] == '>' || lex->line[i] == '<' || lex->line[i] == '|' ||
			lex->line[i] == '&' || lex->line[i] == ';')
		return (-1);
	tmp = ft_strsub(lex->line, lex->tl, lex->hd - lex->tl);
	if ((token_ht = add_token(lex, token_ht, tmp, 9)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (i);
}

int			is_redir(t_lex *lex, t_token_ht *token_ht, int i)
{
	if (lex->line[i] == '>' && lex->line[i + 1] == '>')
		i = is_add(lex, token_ht, i);
	else if (lex->line[i] == '<' && lex->line[i + 1] == '<')
		i = is_heredoc(lex, token_ht, i);
	else if (lex->line[i] == '<' && lex->line[i - 1] != '<')
		i = is_in(lex, token_ht, i);
	else if (lex->line[i] == '>' && lex->line[i - 1] != '>')
		i = is_replace(lex, token_ht, i);
	else
		return (0);
	if (lex->fd[0] != -1 || lex->fd[1] != -1)
	{
		lex->fd[0] = -1;
		lex->fd[0] = -1;
	}
	return (i);
}
