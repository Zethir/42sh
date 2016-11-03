/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:55:39 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/03 18:59:22 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		deal_with_dash_bis(t_shell *sh, char **cmd, int fd, int i)
{
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
		{
			i = 0;
			while (line[i] != ' ')
				i++;
			tmp = ft_strdup(&line[i]);
			free(line);
			exec_cmd_lst(sh, cmd, tmp);
			return ;
		}
		free(line);
		i--;
	}
	free(line);
}

static void		deal_with_dash(t_shell *sh, char **cmd, int fd)
{
	t_hist	*hist;
	int		i;

	hist = sh->hist;
	i = 0;
	while (sh->hist->prev)
	{
		sh->hist = sh->hist->prev;
		i++;
	}
	sh->hist = hist;
	i = i - ft_atoi(&cmd[0][2]) + 1;
	deal_with_dash_bis(sh, cmd, fd, i);
}

static void		deal_with_number(t_shell *sh, char **cmd, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	i = ft_atoi(&cmd[0][1]);
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
		{
			i = 0;
			while (line[i] != ' ')
				i++;
			tmp = ft_strdup(&line[i]);
			free(line);
			exec_cmd_lst(sh, cmd, tmp);
			return ;
		}
		free(line);
		i--;
	}
	free(line);
}

static void		deal_with_string(t_shell *sh, char **cmd)
{
	t_hist	*hist;
	char	*line;

	hist = sh->hist;
	line = NULL;
	while (sh->hist->prev)
	{
		if (ft_strncmp(sh->hist->str, &cmd[0][1], ft_strlen(&cmd[0][1])) == 0)
		{
			line = ft_strdup(sh->hist->str);
			sh->hist = hist;
			exec_cmd_lst(sh, cmd, line);
			break ;
		}
		sh->hist = sh->hist->prev;
	}
	sh->hist = hist;
}

int				do_designator(t_shell *sh, char **cmd)
{
	int		fd;

	if ((fd = open("/tmp/history", O_RDONLY)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return (-1);
	}
	if (cmd[0][1] == '-')
	{
		if (check_number_bis(cmd) == 0)
			deal_with_dash(sh, cmd, fd);
	}
	else if (cmd[0][1] >= '0' && cmd[0][1] <= '9')
	{
		if (check_number(cmd) == 0)
			deal_with_number(sh, cmd, fd);
	}
	else if (cmd[0][1])
	{
		if (check_alpha(cmd) == 0)
			deal_with_string(sh, cmd);
	}
	close(fd);
	return (0);
}
