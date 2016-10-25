/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:48:35 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/25 14:29:04 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int		hub_trunc_add_heredoc(t_shell *sh, t_token *token)
{
	if (token->next && token->token_value == R_ADD)
		append_redir(sh, token, token->next->cmd);
	else if (token->next && token->token_value == R_TRUNC)
		truncate_redir(sh, token, token->next->cmd);
	else if (token->next && token->token_value == HEREDOC)
		heredoc(sh, token->next->cmd);
	else
		return (-1);
	return (0);
}

static int		hub_in_trunc_fd(t_shell *sh, t_token *token, t_token *tmp)
{
	if (token->token_value == R_TRUNC_FD_CLOSE)
	{
		if (out_fd_close(sh, token, tmp) == 0)
			return (-1);
		else
			return (1);
	}
	else if (token->token_value == R_IN_FD_CLOSE)
	{
		if (in_fd_close(sh, token, tmp) == 0)
			return (-1);
		else
			return (1);
	}
	else if (token->token_value == R_IN_FD ||
				token->token_value == R_TRUNC_FD)
	{
		if (trunc_in_fd(sh, token, tmp) == 0)
			return (-1);
		else
			return (1);
	}
	return (0);
}

t_token			*hub_redir(t_shell *sh, t_token *token)
{
	t_token	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (token)
	{
		if ((i = hub_in_trunc_fd(sh, token, tmp)) == -1)
			break ;
		else if (i == 0)
		{
			if (token->next && token->token_value == R_IN)
			{
				if (input_redir(sh, token, token->next->cmd) == -1)
					return (NULL);
			}
			else if (hub_trunc_add_heredoc(sh, token) == -1)
			{
				token->cmd = ft_strdup(tmp->cmd);
				break ;
			}
		}
		token = token->next;
	}
	return (token);
}
