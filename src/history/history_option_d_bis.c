/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_d_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:07:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/11 18:43:25 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int			check_if_out_of_range(char **cmd, int nbr, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	free(line);
	if (nbr >= i - 1)
	{
		out_of_range_error(cmd);
		return (1);
	}
	return (0);
}
