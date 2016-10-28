/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 19:10:54 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 13:48:18 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void	get_first_fd(t_lex *lex, int i)
{
	char	*str;
	int		j;

	j = i - 1;
	while (j > 0 && ft_isdigit(lex->line[j]))
		j--;
	if (j != i - 1)
	{
		str = ft_strsub(lex->line, j, i - j);
		lex->fd[0] = ft_atoi(str);
		free(str);
		lex->hd = j;
	}
}

int		get_second_fd(t_lex *lex, int i)
{
	char	*str;
	int		j;

	j = i;
	while (lex->line[j] && ft_isdigit(lex->line[j]))
		j++;
	if (j != i)
	{
		str = ft_strsub(lex->line, i, j - i);
		lex->fd[1] = ft_atoi(str);
		free(str);
		return (j);
	}
	else
		return (-1);
}
