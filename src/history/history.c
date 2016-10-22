/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:20:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 17:57:51 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void	history_option(t_hub *info, char **cmd, int fd)
{
	t_dlist	*dlist;
	int		nbr;
	char	*line;
	int		i;

	i = 0;
	dlist = info->node;
	if (numeric_error(cmd) == 1)
		return ;
	nbr = ft_atoi(cmd[1]);
	while (info->node->prev)
	{
		info->node = info->node->prev;
		i++;
	}
	info->node = dlist;
	nbr = i - nbr;
	while (get_next_line(fd, &line) > 0)
	{
		if (nbr < 0)
			ft_putendl(line);
		nbr--;
	}
}

int			do_history(t_hub *info, char **cmd)
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
			ft_putendl(line);
	}
	else if (cmd[1])
	{
		if (cmd[1][0] == '-')
			do_option(info, cmd);
		else
			history_option(info, cmd, fd);
	}
	close(fd);
	return (0);
}

void		add_history(t_hub *info)
{
	char	*buf;
	int		fd;
	int		i;
	char	*str;

	i = 0;
	if ((fd = open("/tmp/history", O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (get_next_line(fd, &buf) > 0)
		i++;
	i += 1;
	str = ft_strjoin(ft_itoa(i), " ");
	str = ft_strjoin(str, info->node->str);
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

void		deal_with_file(t_hub *info)
{
	int		fd;
	char	*line;

	if ((fd = open("/tmp/history", O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (1)
	{
		if (get_next_line(fd, &line) != 1)
			break ;
		line = split_line(line);
		info->node->str = line;
		push_node_bis(&info->node, create_node());
		info->node = info->node->next;
	}
	close(fd);
}
