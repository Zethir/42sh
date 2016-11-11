/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:52:09 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/11 18:49:41 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int	history_option(t_shell *sh, char **cmd, int fd)
{
	t_hist	*hist;
	int		nbr;
	char	*line;
	int		i;

	i = 0;
	hist = sh->hist;
	if (numeric_error(cmd) == 1)
		return (1);
	nbr = ft_atoi(cmd[1]);
	while (hist->prev)
	{
		hist = hist->prev;
		i++;
	}
	nbr = i - 1 - nbr;
	while (get_next_line(fd, &line) > 0)
	{
		if (nbr < 0)
			ft_putendl(line);
		free(line);
		nbr--;
	}
	free(line);
	return (0);
}

static int	do_history_bis(t_shell *sh, char **cmd, int fd)
{
	char	*line;

	if (!cmd[1])
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl(line);
			free(line);
		}
		free(line);
	}
	else if (cmd[1])
	{
		if (cmd[1][0] == '-')
		{
			if (do_option(sh, cmd, fd) == 1)
				return (1);
		}
		else
		{
			if (history_option(sh, cmd, fd) == 1)
				return (1);
		}
	}
	return (0);
}

int			open_history(void)
{
	int		fd;

	if ((fd = open("/tmp/history", O_RDONLY)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return (-1);
	}
	return (fd);
}

int			do_history(t_shell *sh, char **cmd)
{
	int		fd;

	if ((fd = open_history()) == -1)
		return (1);
	if (do_history_bis(sh, cmd, fd) == 1)
		return (1);
	close(fd);
	return (0);
}
