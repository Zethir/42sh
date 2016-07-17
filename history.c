/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:20:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/17 19:25:44 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	history_option(t_struct *info, char **cmd, int fd)
{
	t_dlist	*dlst;
	int		nbr;
	int		i;
	char	*line;

	i = 0;
	dlst = info->node;
	if (numeric_error(cmd) == 1)
		return ;
	nbr = ft_atoi(cmd[1]);
	while (info->node->prev)
	{
		info->node = info->node->prev;
		i++;
	}
	info->node = dlst;
	nbr = i - nbr;
	while (get_next_line(fd, &line) > 0)
	{
		if (nbr < 0)
			ft_putendl(line);
		nbr--;
	}
}

int			do_history(t_struct *info, char **cmd)
{
	int		fd;
	char	*str;
	char	*line;

	str = get_home(info->lst);
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("history");
		exit(-1);
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
	return (-1);
}

void		add_history(t_struct *info)
{
	char	*buf;
	int		fd;
	int		i;
	char	*str;

	i = 0;
	str = get_home(info->lst);
	if ((fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
	{
		perror("history");
		exit(-1);
	}
	while (get_next_line(fd, &buf) > 0)
		i++;
	i += 1;
	str = ft_strjoin(ft_itoa(i), " ");
	str = ft_strjoin(str, info->node->str);
	ft_putendl_fd(str, fd);
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

void		deal_with_file(t_struct *info)
{
	int		fd;
	char	*line;
	char	*str;

	str = get_home(info->lst);
	if ((fd = open(str, O_RDWR | O_CREAT, 0644)) == -1)
	{
		perror("history");
		exit(-1);
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
