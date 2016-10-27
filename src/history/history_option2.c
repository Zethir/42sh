/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:11:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 17:58:30 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		print_in_file(char *cmd, int fd, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(i);
	tmp2 = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strjoin(tmp2, cmd);
	ft_putendl_fd(tmp, fd);
	free(tmp);
	free(tmp2);
}

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
			print_in_file(hist->str, fd, i);
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

static void		refresh_hist(t_shell *sh, char *line)
{
	char	*tmp;

	tmp = ft_strdup(split_line(line));
	free(line);
	sh->hist = init_hist(tmp);
	push_hist(&sh->head, sh->hist);
	free(tmp);
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
		refresh_hist(sh, line);
	add_to_file(sh);
	free(sh->hist->str);
	sh->hist->str = ft_strdup(str);
	close(fd);
	free(str);
}
