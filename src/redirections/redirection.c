/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:27:10 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/09 18:44:27 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		*truncate_redir(char *filename)
{
	int		stdio[3];
	int		fd;

	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
		fd = 1;
	stdio[0] = 0;
	stdio[1] = fd;
	stdio[2] = 2;
}

static int		*append_redir(char *filename)
{
	int		stdio[3];
	int		fd;

	if ((fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
		fd = 1;
	stdio[0] = 0;
	stdio[1] = fd;
	stdio[2] = 2;
	return (stdio);
}

static int		*input_redir(char *filename)
{
	int		stdio[3];
	int		fd;

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
	int		stdio[3];

	stdio[0] = 0;
	stdio[1] = 1;
	stdio[2] = 2;
	while (token)
	{
		if (token->value == R_ADD ||
				token->value == R_ADD_FD)
			stdio = append_redir(token->next->cmd);
		else if (token->value == R_TRUNC ||
				token->value == R_TRUNC_FD)
			stdio = truncate_redir(token->next->cmd);
		else if (token->value == R_IN ||
				token->value == R_IN_FD)
			stdio = input_redir(token->next->cmd);
		else
		{
			create_process(job, token, stdio);
			break;
		}
		token = token->next;
	}
	return (token);
}
