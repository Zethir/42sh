/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:11:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/27 17:07:06 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void		add_to_file(t_env_hist *info, char *str)
{
	t_dlist	*dlst;
	char	*pathb;
	int		fd;
	int		i;

	i = 1;
	dlst = info->node;
	pathb = ft_strjoin(str, "bis");
	if ((fd = open(pathb, O_RDWR | O_CREAT, 0644)) == -1)
	{
		perror("history");
		exit(-1);
	}
	while (info->node->prev)
		info->node = info->node->prev;
	while (info->node)
	{
		ft_putendl_fd(ft_strjoin(ft_strjoin(ft_itoa(i), " "),
					info->node->str), fd);
		info->node = info->node->next;
		i++;
	}
	info->node = dlst;
	unlink(str);
	rename(pathb, str);
}

void		option_r(t_env_hist *info, char *str)
{
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDWR | O_CREAT, 0644)) == -1)
	{
		perror("history");
		exit(-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		line = split_line(line);
		info->node->str = line;
		push_node_bis(&info->node, create_node());
		info->node = info->node->next;
	}
	add_to_file(info, str);
	close(fd);
}
