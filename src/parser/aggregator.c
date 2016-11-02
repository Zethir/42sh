/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 18:29:05 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/02 16:09:17 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int		out_fd_close(t_shell *sh, t_token *token, t_token *tmp)
{
	char	*str;

	if (token->fd[0] != -1)
		sh->closefd = token->fd[0];
	else
		sh->closefd = 1;
	if (token->next)
	{
		str = ft_strjoin(tmp->cmd, " ");
		free(tmp->cmd);
		tmp->cmd = ft_strjoin(str, token->next->cmd);
		free(str);
		return (1);
	}
	else
	{
		token->token_value = 13;
		return (0);
	}
}

int		in_fd_close(t_shell *sh, t_token *token, t_token *tmp)
{
	char	*str;

	if (token->fd[0] != -1)
		sh->closefd = token->fd[0];
	else
		sh->closefd = 0;
	if (token->next)
	{
		str = ft_strjoin(tmp->cmd, " ");
		free(tmp->cmd);
		tmp->cmd = ft_strjoin(str, token->next->cmd);
		free(str);
		return (1);
	}
	else
	{
		token->token_value = 13;
		return (0);
	}
}

int		trunc_in_fd(t_shell *sh, t_token *token, t_token *tmp)
{
	char	*str;

	str = NULL;
	if (token->fd[0] == 0)
		sh->stdio[0] = token->fd[1];
	if (token->fd[0] == 1 || token->fd[0] == -1)
		sh->stdio[1] = token->fd[1];
	if (token->fd[0] == 2)
		sh->stdio[2] = token->fd[1];
	if (token->next)
	{
		str = ft_strjoin(tmp->cmd, " ");
		free(tmp->cmd);
		tmp->cmd = ft_strjoin(str, token->next->cmd);
		free(str);
		return (1);
	}
	else
	{
		token->token_value = 13;
		return (0);
	}
}
