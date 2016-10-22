/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:48:35 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 11:49:34 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int		hub_trunc_add_heredoc(t_hub *info, t_token *token)
{
	if (token->next && token->token_value == R_ADD)
		append_redir(info, token, token->next->cmd);
	else if (token->next && token->token_value == R_TRUNC)
		truncate_redir(info, token, token->next->cmd);
	else if (token->next && token->token_value == HEREDOC)
		heredoc(info, token->next->cmd);
	else
		return (-1);
	return (0);
}

static int		hub_in_trunc_fd(t_hub *info, t_token *token, t_token *tmp)
{
	if (token->token_value == R_TRUNC_FD_CLOSE)
	{
		if (out_fd_close(info, token, tmp) == 0)
			return (-1);
		else
			return (1);
	}
	else if (token->token_value == R_IN_FD_CLOSE)
	{
		if (in_fd_close(info, token, tmp) == 0)
			return (-1);
		else
			return (1);
	}
	else if (token->token_value == R_IN_FD ||
				token->token_value == R_TRUNC_FD)
	{
		if (trunc_in_fd(info, token, tmp) == 0)
			return (-1);
		else
			return (1);
	}
	return (0);
}

t_token			*hub_redir(t_hub *info, t_token *token)
{
	t_token	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (token)
	{
		if ((i = hub_in_trunc_fd(info, token, tmp)) == -1)
			break ;
		else if (i == 0)
		{
			if (token->next && token->token_value == R_IN)
			{
				if (input_redir(info, token, token->next->cmd) == -1)
					return (NULL);
			}
			else if (hub_trunc_add_heredoc(info, token) == -1)
			{
				token->cmd = ft_strdup(tmp->cmd);
				break ;
			}
		}
		token = token->next;
	}
	return (token);
}
