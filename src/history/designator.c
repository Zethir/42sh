/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:55:39 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 13:07:30 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		exec_cmd_add_lst(t_shell *sh, char **cmd, char *line)
{
	char	**tabl;
	char	**env;
	int		i;

	i = 0;
	env = NULL;
	while (*cmd)
	{
		line = ft_strjoin(line, " ");
		line = ft_strjoin(line, *cmd);
		cmd++;
	}
	tabl = ft_strsplit_ws(line);
	sh->hist->str = ft_strdup("");
	while (tabl[i])
	{
		ft_putstr(tabl[i]);
		if (i != 0)
			sh->hist->str = ft_strjoin(sh->hist->str, " ");
		sh->hist->str = ft_strjoin(sh->hist->str, tabl[i]);
		ft_putchar(' ');
		i++;
	}
	ft_strdel(tabl);
	ft_putchar('\n');
	env = get_env(sh->env);
	exec_env(sh, sh->hist->str, env);
	free(env);
}

static void		deal_with_dash(t_shell *sh, char **cmd, int fd)
{
	int		i;
	t_hist	*hist;
	char	*line;

	hist = sh->hist;
	i = 0;
	while (sh->hist->prev)
	{
		sh->hist = sh->hist->prev;
		i++;
	}
	sh->hist = hist;
	i = i - ft_atoi(&cmd[0][2]);
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
		{
			while (*line != ' ')
				line++;
			cmd++;
			exec_cmd_add_lst(sh, cmd, line);
		}
		i--;
	}
	free(line);
}

static void		deal_with_number(t_shell *sh, char **cmd, int fd)
{
	char	*line;
	int		i;

	i = ft_atoi(&cmd[0][1]);
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
		{
			while (*line != ' ')
				line++;
			cmd++;
			exec_cmd_add_lst(sh, cmd, line);
		}
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
			cmd++;
			sh->hist = hist;
			exec_cmd_add_lst(sh, cmd, line);
			break ;
		}
		sh->hist = sh->hist->prev;
	}
	free(line);
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
