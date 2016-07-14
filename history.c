/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:20:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/14 17:32:55 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		add_history(char *line)
{
	char	*buf;
	int		fd;

	if ((fd = open("history", O_RDWR | O_APPEND)) == -1)
	{
		perror("history");
		exit (-1);
	}
	while (1)
	{
		if (get_next_line(fd, &buf) == 0)
			break;
		printf("%s\n", buf);
	}
	printf("%s\n", line);
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

	if ((fd = open("history", O_RDWR | O_CREAT, 0644)) == -1)
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
