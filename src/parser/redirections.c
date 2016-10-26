/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:49:07 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/25 20:33:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void			truncate_redir(t_shell *sh, t_token *token, char *filename)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
		fd = 1;
	if (token->fd[0] == 0)
		sh->stdio[0] = fd;
	if (token->fd[0] == 1 || token->fd[0] == -1)
		sh->stdio[1] = fd;
	if (token->fd[0] == 2)
		sh->stdio[2] = fd;
}

void			append_redir(t_shell *sh, t_token *token, char *filename)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
		fd = 1;
	if (token->fd[0] == 0)
		sh->stdio[0] = fd;
	if (token->fd[0] == 1 || token->fd[0] == -1)
		sh->stdio[1] = fd;
	if (token->fd[0] == 2)
		sh->stdio[2] = fd;
}

int				input_redir(t_shell *sh, t_token *token, char *filename)
{
	int		fd;

	filename = ft_wipespace(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("42sh: No such file: ");
		ft_putendl(filename);
		return (-1);
	}
	if (token->fd[0] == 0 || token->fd[0] == -1)
		sh->stdio[0] = fd;
	if (token->fd[0] == 1)
		sh->stdio[1] = fd;
	if (token->fd[0] == 2)
		sh->stdio[2] = fd;
	return (0);
}

void			heredoc(t_shell *sh, char *code)
{
	int		pipefd[2];
	char	*line;

	line = "";
	pipe(pipefd);
	code = ft_wipespace(code);
	while (ft_strcmp(line, code))
	{
		line = deal_with_termcap(sh->hist);
		if (line && ft_strcmp(line, code))
		{
			ft_putendl_fd(line, pipefd[1]);
			free(line);
		}
		ft_putchar('\n');
	}
	sh->stdio[0] = pipefd[0];
	close(pipefd[1]);
}
