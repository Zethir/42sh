/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:09:15 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/03 22:21:38 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		option_d_free_node(t_shell *sh)
{
	t_hist	*hist;

	hist = NULL;
	if (sh->hist->prev)
	{
		sh->hist->prev->next = sh->hist->next;
		sh->hist->next->prev = sh->hist->prev;
		free(sh->hist->str);
		free(sh->hist);
	}
	else
	{
		hist = sh->hist;
		sh->hist = sh->hist->next;
		sh->hist->prev = NULL;
		free(hist->str);
		free(hist);
		sh->head = sh->hist;
	}
}

static void		option_d_update_hist(t_shell *sh, int fd, int *i)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(*i);
	str = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strjoin(str, sh->hist->str);
	free(str);
	ft_putendl_fd(tmp, fd);
	free(tmp);
	(*i)++;
}

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
			option_d_update_hist(sh, fd, &i);
		if (nbr == 0)
			option_d_free_node(sh);
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
	if (check_if_out_of_range(cmd, nbr) == 1)
		return ;
	nbr = option_dbis2(sh, nbr, fd);
	unlink("/tmp/history");
	rename(pathb, "/tmp/history");
	free(pathb);
}

void			option_d(t_shell *sh, char **cmd)
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
