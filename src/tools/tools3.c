/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 00:06:48 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/16 13:09:58 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sh42.h"

int		start_pipe(int pipefds[], int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		if (pipe(pipefds + (i * 2)) < 0)
		{
			perror("couldn't pipe");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	close_pipefds(int pipefds[], int num)
{
	int		i;

	i = 0;
	while (i < 2 * num)
	{
		close(pipefds[i]);
		i++;
	}
}

void	wait_for_child(int num)
{
	int		i;

	i = 0;
	while (i < num + 1)
	{
		wait(0);
		i++;
	}
}

char	*get_home(t_lst *node)
{
	char	*str;

	str = ft_strdup("");
	while (node)
	{
		if (ft_strcmp(node->name, "HOME") == 0)
		{
			str = ft_strjoin(ft_strchr(node->line, '/'), "/history");
			break ;
		}
		node = node->next;
	}
	return (str);
}
