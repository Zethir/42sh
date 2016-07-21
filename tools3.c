/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 00:06:48 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/18 17:07:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		check_for_chevron(t_struct *ptr)
{
	int		i;

	i = 1;
	while (ptr->arg[i])
	{
		if (ft_strstr(ptr->arg[i], ">") != NULL)
			return (1);
		else if (ft_strstr(ptr->arg[i], ">>") != NULL)
			return (1);
		else if (ft_strstr(ptr->arg[i], "<") != NULL)
			return (1);
		else if (ft_strstr(ptr->arg[i], "<<") != NULL)
			return (1);
		i++;
	}
	return (0);
}

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
