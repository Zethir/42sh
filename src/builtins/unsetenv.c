/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 14:30:24 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int			do_unsetenv(t_lst *node, char **arg, int flag)
{
	t_lst	*tmp;

	arg++;
	tmp = node;
	if (!*arg)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (-1);
	}
	else
	{
		while (*arg)
		{
			while (node)
			{
				if (ft_strcmp(node->name, *arg) == 0 && node->flag == flag)
					node->line = NULL;
				node = node->next;
			}
			node = tmp;
			arg++;
		}
	}
	return (0);
}
