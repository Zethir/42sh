/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:20:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 15:51:01 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void	add_history_bis(t_shell *sh, int i, int fd)
{
	char	*str;
	char	*tmp;

	i += 1;
	tmp = ft_itoa(i);
	str = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strjoin(str, sh->hist->str);
	free(str);
	ft_putendl_fd(tmp, fd);
	free(tmp);
}

void		add_history(t_shell *sh)
{
	char	*buf;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open("/tmp/history", O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (get_next_line(fd, &buf) > 0)
	{
		free(buf);
		i++;
	}
	free(buf);
	add_history_bis(sh, i, fd);
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

void		deal_with_file(t_shell *sh)
{
	int		fd;
	char	*line;
	char	*tmp;

	sh->head = NULL;
	if ((fd = open("/tmp/history", O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	while (1)
	{
		if (get_next_line(fd, &line) != 1)
			break ;
		tmp = ft_strdup(split_line(line));
		free(line);
		sh->hist = init_hist(tmp);
		push_hist(&sh->head, sh->hist);
		free(tmp);
	}
	free(line);
	close(fd);
}
