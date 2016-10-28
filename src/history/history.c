/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:20:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 13:24:09 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void	history_option(t_shell *sh, char **cmd, int fd)
{
	t_hist	*hist;
	int		nbr;
	char	*line;
	int		i;

	i = 0;
	hist = sh->hist;
	if (numeric_error(cmd) == 1)
		return ;
	nbr = ft_atoi(cmd[1]);
	while (sh->hist->prev)
	{
		sh->hist = sh->hist->prev;
		i++;
	}
	sh->hist = hist;
	nbr = i - 1 - nbr;
	while (get_next_line(fd, &line) > 0)
	{
		if (nbr < 0)
			ft_putendl(line);
		free(line);
		nbr--;
	}
}

int			do_history(t_shell *sh, char **cmd)
{
	int		fd;
	char	*line;

	if ((fd = open("/tmp/history", O_RDONLY)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return (-1);
	}
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
			do_option(sh, cmd);
		else
			history_option(sh, cmd, fd);
	}
	close(fd);
	return (0);
}

void		add_history(t_shell *sh)
{
	char	*buf;
	char	*str;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open("/tmp/history", O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (get_next_line(fd, &buf) > 0)
	{	
		free(buf);
		i++;
	}
	free(buf);
	i += 1;
	tmp = ft_itoa(i);
	buf = ft_strjoin(tmp, " ");
	str = ft_strjoin(buf, sh->hist->str);
	free(buf);
	free(tmp);
	ft_putendl_fd(str, fd);
	free(str);
	close(fd);
}

char		*split_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 32)
		{
			while (line[i] == 32)
				i++;
			break ;
		}
		i++;
	}
	return (&line[i]);
}

void		deal_with_file(t_shell *sh)
{
	int		fd;
	char	*line;
	char	*tmp;

	sh->head = NULL;
	if ((fd = open("/tmp/history", O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (1)
	{
		if (get_next_line(fd, &line) != 1)
			break ;
		tmp = ft_strdup(split_line(line));
		free(line);
		sh->hist = init_hist(tmp);
		push_hist(&sh->head, sh->hist);
		free(tmp);
	}
	free(line);
	close(fd);
}
