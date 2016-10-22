/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:04:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 11:26:20 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int		option_dbis2(t_hub *info, int nbr, int fd)
{
	t_dlist	*dlst;
	int		i;

	dlst = info->node;
	i = 1;
	while (info->node->prev)
		info->node = info->node->prev;
	while (info->node)
	{
		if (nbr != 0)
		{
			ft_putendl_fd(ft_strjoin(ft_strjoin(ft_itoa(i), " "),
					info->node->str), fd);
			i++;
		}
		if (nbr == 0)
		{
			info->node->prev->next = info->node->next;
			info->node->next->prev = info->node->prev;
		}
		nbr--;
		info->node = info->node->next;
	}
	info->node = dlst;
	return (nbr);
}

static void		option_dbis(t_hub *info, char **cmd)
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
		return ;
	}
	nbr = option_dbis2(info, nbr, fd);
	unlink("/tmp/history");
	rename(pathb, "/tmp/history");
	if (nbr > 0)
	{
		out_of_range_error(cmd);
		return ;
	}
}

static void		option_d(t_hub *info, char **cmd)
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
	option_dbis(info, cmd);
}

void			do_option(t_hub *info, char **cmd)
{
	int		fd;

	if (ft_strcmp(cmd[1], "-c") == 0)
	{
		if ((fd = open("/tmp/history", O_WRONLY | O_TRUNC, 0644)) == -1)
		{
			ft_putendl_fd("history : No such file or directory", 2);
			return ;
		}
	}
	else if (ft_strcmp(cmd[1], "-d") == 0)
	{
		if (!cmd[2])
			ft_putendl_fd("Need entry number to execute", 2);
		else
			option_d(info, cmd);
	}
	else if (ft_strcmp(cmd[1], "-r") == 0)
	{
		if (!cmd[2])
			option_r(info);
		else
			ft_putendl_fd("Option [-r] doesn't need any arguments", 2);
	}
}
