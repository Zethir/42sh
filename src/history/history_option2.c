/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:11:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 16:05:50 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		add_to_file_bis(t_shell *sh, int fd)
{
	t_hist	*hist;
	int		i;

	i = 1;
	hist = sh->hist;
	while (hist->prev)
		hist = hist->prev;
	while (hist)
	{
		if (hist->str)
		{
			ft_putendl_fd(ft_strjoin(ft_strjoin(ft_itoa(i), " "),
						hist->str), fd);
		}
		hist = hist->next;
		i++;
	}
}

static void		add_to_file(t_shell *sh)
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
	add_to_file_bis(sh, fd);
	unlink("/tmp/history");
	rename(pathb, "/tmp/history");
	free(pathb);
}

void			option_r(t_shell *sh)
{
	int		fd;
	char	*line;
	char	*str;

	str = ft_strdup(sh->hist->str);
	if ((fd = open("/tmp/history", O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (get_next_line(fd, &line) > 0)
	{
		line = split_line(line);
		sh->hist->str = line;
		push_node_bis(&sh->hist, create_node());
		sh->hist = sh->hist->next;
	}
	add_to_file(sh);
	sh->hist->str = ft_strdup(str);
	close(fd);
	free(str);
}
