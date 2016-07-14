/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:20:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/14 18:28:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		add_history(char *line)
{
	char	*buf;
	int		fd;
	int		i;
	char	*str;

	i = 0;
	if ((fd = open("/nfs/2015/c/cboussau/history", O_RDWR | O_APPEND)) == -1)
	{
		perror("history");
		exit (-1);
	}
	while (get_next_line(fd, &buf) > 0)
		i++;
	i += 1;
	str = ft_strjoin(ft_itoa(i), " ");
	line = ft_strjoin(str, ft_strjoin(line, "\n"));
	write(fd, line, ft_strlen(line));
	close(fd);
}


static char	*split_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 32)
		{
			while (line[i] == 32)
				i++;
			break;
		}
		i++;
	}
	return (&line[i]);
}

void		deal_with_file(t_struct *info)
{
	int		fd;
	char	*line;

	if ((fd = open("/nfs/2015/c/cboussau/history", O_RDWR | O_CREAT, 0644)) == -1)
	{
		perror("history");
		exit (-1);
	}
	while (1)
	{
		if (get_next_line(fd, &line) != 1)
			break;
		line = split_line(line);
		info->node->str = line;
		push_node_bis(&info->node, create_node());
		info->node = info->node->next;
	}
}
