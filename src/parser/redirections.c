/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:49:07 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/05 11:44:26 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void			truncate_redir(t_shell *sh, t_token *token, char *filename)
{
	char	*str;
	int		fd;

	str = ft_wipespace(filename);
	if ((fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
		fd = 1;
	if (token->fd[0] == 0)
		sh->stdio[0] = fd;
	if (token->fd[0] == 1 || token->fd[0] == -1)
		sh->stdio[1] = fd;
	if (token->fd[0] == 2)
		sh->stdio[2] = fd;
	free(str);
}

void			append_redir(t_shell *sh, t_token *token, char *filename)
{
	char	*str;
	int		fd;

	str = ft_wipespace(filename);
	if ((fd = open(str, O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
		fd = 1;
	if (token->fd[0] == 0)
		sh->stdio[0] = fd;
	if (token->fd[0] == 1 || token->fd[0] == -1)
		sh->stdio[1] = fd;
	if (token->fd[0] == 2)
		sh->stdio[2] = fd;
	free(str);
}

int				input_redir(t_shell *sh, t_token *token, char *filename)
{
	char	*str;
	int		fd;

	str = ft_wipespace(filename);
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("42sh: No such file: ", 2);
		ft_putendl(filename);
		free(str);
		return (-1);
	}
	if (token->fd[0] == 0 || token->fd[0] == -1)
		sh->stdio[0] = fd;
	if (token->fd[0] == 1)
		sh->stdio[1] = fd;
	if (token->fd[0] == 2)
		sh->stdio[2] = fd;
	free(str);
	return (0);
}

static int		heredoc_cmp(char *line, char *str, int pipefd[2])
{
	if (line && line[0] == 4 && !ft_strcmp(str, "EOF"))
	{
		free(line);
		ft_putchar('\n');
		return (1);
	}
	else if (line && ft_strcmp(line, str))
	{
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	else if (line)
	{
		free(line);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

void			heredoc(t_shell *sh, char *code)
{
	int		pipefd[2];
	char	*line;
	char	*str;

	pipe(pipefd);
	str = ft_wipespace(code);
	while (1)
	{
		line = termcap_heredoc(sh);
		if (heredoc_cmp(line, str, pipefd) == 1)
			break ;
		ft_putchar('\n');
	}
	free(str);
	sh->stdio[0] = pipefd[0];
	close(pipefd[1]);
}
