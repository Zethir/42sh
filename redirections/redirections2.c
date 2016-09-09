/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:31:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/09 16:01:30 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

void		data_series(t_struct *ptr, int i)
{
	int		fd[2];
	char	*line;

	i += 1;
	pipe(fd);
	while (1)
	{
		line = deal_with_termcap(ptr);
		ft_putchar('\n');
		if (ft_strcmp(line, ptr->arg[i]) == 0)
			break ;
		ft_putendl_fd(line, fd[1]);
		line = ft_strdup("");
	}
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
}

void		redirection_err_out(t_struct *ptr, int i)
{
	int		ret;

	i += 1;
	if ((ret = open(ptr->arg[i], O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
	{
		perror(ptr->arg[i]);
		exit(-1);
	}
	dup2(ret, 1);
	dup2(ret, 2);
	close(ret);
}

void		redirection_in(t_struct *ptr, int fd, int i)
{
	int		ret;

	i += 1;
	if ((ret = open(ptr->arg[i], O_RDONLY)) == -1)
	{
		perror(ptr->arg[i]);
		exit(-1);
	}
	else
	{
		dup2(ret, fd);
		close(ret);
	}
}

char		**save_command(t_struct *ptr)
{
	char	**str;
	int		i;

	i = 0;
	if (!(str = (char **)malloc(sizeof(char *) * ft_tablen(ptr->arg))))
		return (NULL);
	while (ptr->arg[i])
	{
		if (ft_strstr(ptr->arg[i], ">") != NULL)
			break ;
		else if (ft_strstr(ptr->arg[i], "<") != NULL)
			break ;
		str[i] = ft_strdup(ptr->arg[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}

void		exec_cmd(t_struct *ptr, char **str)
{
	char	*path;

	path = ft_strjoin(*ptr->right_path, ptr->arg[0]);
	if (execve(path, str, ptr->env) < 0)
	{
		no_command_error(ptr->arg[0]);
		exit(-1);
	}
}
