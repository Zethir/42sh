/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 18:29:05 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 15:39:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int		out_fd_close(t_shell *sh, t_token *token, t_token *tmp)
{
	if (token->fd[0] != -1)
		sh->closefd = token->fd[0];
	else
		sh->closefd = 1;
	if (token->next)
	{
		tmp->cmd = ft_strjoin(tmp->cmd, " ");
		tmp->cmd = ft_strjoin(tmp->cmd, token->next->cmd);
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
	if (token->fd[0] != -1)
		sh->closefd = token->fd[0];
	else
		sh->closefd = 0;
	if (token->next)
	{
		tmp->cmd = ft_strjoin(tmp->cmd, " ");
		tmp->cmd = ft_strjoin(tmp->cmd, token->next->cmd);
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
	if (token->fd[0] == 0)
		sh->stdio[0] = token->fd[1];
	if (token->fd[1] == 1 || token->fd[1] == -1)
		sh->stdio[1] = token->fd[1];
	if (token->fd[2] == 1)
		sh->stdio[2] = token->fd[1];
	if (token->next)
	{
		tmp->cmd = ft_strjoin(tmp->cmd, " ");
		tmp->cmd = ft_strjoin(tmp->cmd, token->next->cmd);
		return (1);
	}
	else
	{
		token->token_value = 13;
		return (0);
	}
}
