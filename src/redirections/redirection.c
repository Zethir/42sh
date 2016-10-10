/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:27:10 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/10 17:15:19 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int		*truncate_redir(char *filename, int *stdio)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
		fd = 1;
	stdio[0] = 0;
	stdio[1] = fd;
	stdio[2] = 2;
	return (stdio);
}

static int		*append_redir(char *filename, int *stdio)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
		fd = 1;
	stdio[0] = 0;
	stdio[1] = fd;
	stdio[2] = 2;
	return (stdio);
}

static int		*input_redir(char *filename, int *stdio)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("42sh: No such file: ");
		ft_putendl(filename);
		return ((int *)-1);
	}
	stdio[0] = fd;
	stdio[1] = 1;
	stdio[2] = 2;
	return (stdio);
}

t_token 		*hub_redir(t_job *job, t_token *token)
{
	t_token	*tmp;
	int		*stdio;

	stdio = (int *)malloc(sizeof(int) * 3);
	tmp = token;
	while (token)
	{
		if (token->next && (token->token_value == R_ADD ||
				token->token_value == R_ADD_FD))
			stdio = append_redir(token->next->cmd, stdio);
		else if (token->next && (token->token_value == R_TRUNC ||
				token->token_value == R_TRUNC_FD))
			stdio = truncate_redir(token->next->cmd, stdio);
		else if (token->next && (token->token_value == R_IN ||
				token->token_value == R_IN_FD))
			stdio = input_redir(token->next->cmd, stdio);
		else
		{
			create_process(job, tmp, stdio);
			break;
		}
		token = token->next;
	}
	return (token);
}
