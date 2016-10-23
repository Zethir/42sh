/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:11:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/23 12:43:58 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		add_to_file_bis(t_hub *info, int fd)
{
	t_dlist	*dlst;
	int		i;

	i = 1;
	dlst = info->node;
	while (dlst->prev)
		dlst = dlst->prev;
	while (dlst)
	{
		if (dlst->str)
		{
			ft_putendl_fd(ft_strjoin(ft_strjoin(ft_itoa(i), " "),
						dlst->str), fd);
		}
		dlst = dlst->next;
		i++;
	}
}

static void		add_to_file(t_hub *info)
{
	char	*pathb;
	int		fd;

	pathb = ft_strjoin("/tmp/history", "bis");
	if ((fd = open(pathb, O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		free(pathb);
		return ;
	}
	add_to_file_bis(info, fd);
	unlink("/tmp/history");
	rename(pathb, "/tmp/history");
	free(pathb);
}

void			option_r(t_hub *info)
{
	int		fd;
	char	*line;
	char	*str;

	str = ft_strdup(info->node->str);
	if ((fd = open("/tmp/history", O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (get_next_line(fd, &line) > 0)
	{
		line = split_line(line);
		info->node->str = line;
		push_node_bis(&info->node, create_node());
		info->node = info->node->next;
	}
	add_to_file(info);
	info->node->str = ft_strdup(str);
	close(fd);
	free(str);
}
