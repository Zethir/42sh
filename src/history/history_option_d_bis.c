/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_d_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:07:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/03 22:16:11 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		check_if_out_of_range(char **cmd, int nbr)
{
	char	*path;
	char	*line;
	int		fd;
	int		i;

	path = ft_strdup("/tmp/history");
	i = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		free(path);
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	free(line);
	printf("nbr = %d\n", nbr);
	printf("i = %d\n", i);
	if (nbr > i + 1)
	{
		out_of_range_error(cmd);
		return (1);
	}
	return (0);
}
