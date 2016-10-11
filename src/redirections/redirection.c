/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:27:10 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/11 17:22:35 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		truncate_redir(t_hub *info, char *filename)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
		fd = 1;
	info->stdio[0] = 0;
	info->stdio[1] = fd;
	info->stdio[2] = 2;
}

static void		append_redir(t_hub *info, char *filename)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
		fd = 1;
	info->stdio[0] = 0;
	info->stdio[1] = fd;
	info->stdio[2] = 2;
}

static void		input_redir(t_hub *info, char *filename)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("42sh: No such file: ");
		ft_putendl(filename);
		return ;
	}
	info->stdio[0] = fd;
	info->stdio[1] = 1;
	info->stdio[2] = 2;
}

t_token 		*hub_redir(t_hub *info, t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (token)
	{
		if (token->next && (token->token_value == R_ADD ||
				token->token_value == R_ADD_FD))
			append_redir(info, token->next->cmd);
		else if (token->next && (token->token_value == R_TRUNC ||
				token->token_value == R_TRUNC_FD))
			truncate_redir(info, token->next->cmd);
		else if (token->next && (token->token_value == R_IN ||
				token->token_value == R_IN_FD))
			input_redir(info, token->next->cmd);
		else
		{
			token->cmd = ft_strdup(tmp->cmd);
			break;
		}
		token = token->next;
	}
	return (token);
}
