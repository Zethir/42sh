/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:04:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 13:07:29 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int		option_dbis2(t_shell *sh, int nbr, int fd)
{
	t_hist	*hist;
	int		i;

	hist = sh->hist;
	i = 1;
	while (sh->hist->prev)
		sh->hist = sh->hist->prev;
	while (sh->hist)
	{
		if (nbr != 0)
		{
			ft_putendl_fd(ft_strjoin(ft_strjoin(ft_itoa(i), " "),
						sh->hist->str), fd);
			i++;
		}
		if (nbr == 0)
		{
			sh->hist->prev->next = sh->hist->next;
			sh->hist->next->prev = sh->hist->prev;
		}
		nbr--;
		sh->hist = sh->hist->next;
	}
	sh->hist = hist;
	return (nbr);
}

static void		option_dbis(t_shell *sh, char **cmd)
{
	char	*pathb;
	int		fd;
	int		nbr;

	pathb = ft_strjoin("/tmp/history", "bis");
	nbr = ft_atoi(cmd[2]);
	nbr -= 1;
	if ((fd = open(pathb, O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		free(pathb);
		return ;
	}
	nbr = option_dbis2(sh, nbr, fd);
	unlink("/tmp/history");
	rename(pathb, "/tmp/history");
	free(pathb);
	if (nbr > 0)
	{
		out_of_range_error(cmd);
		return ;
	}
}

static void		option_d(t_shell *sh, char **cmd)
{
	int		i;

	i = 0;
	while (cmd[2][i])
	{
		if (cmd[2][i] < '0' || cmd[2][i] > '9')
		{
			out_of_range_error(cmd);
			return ;
		}
		i++;
	}
	option_dbis(sh, cmd);
}

static void		option_c(t_shell *sh)
{
	int		fd;
	char	*str;

	if ((fd = open("/tmp/history", O_WRONLY | O_TRUNC, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	str = ft_strdup(sh->hist->str);
	sh->hist = create_hist();
	sh->hist->str = ft_strdup(str);
	free(str);
}

void			do_option(t_shell *sh, char **cmd)
{
	if (ft_strcmp(cmd[1], "-c") == 0)
		option_c(sh);
	else if (ft_strcmp(cmd[1], "-d") == 0)
	{
		if (!cmd[2])
			ft_putendl_fd("Need entry number to execute", 2);
		else
			option_d(sh, cmd);
	}
	else if (ft_strcmp(cmd[1], "-r") == 0)
	{
		if (!cmd[2])
			option_r(sh);
		else
			ft_putendl_fd("Option [-r] doesn't need any arguments", 2);
	}
}
