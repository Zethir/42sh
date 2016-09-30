/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/29 15:56:47 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int			do_unsetenv(t_lst *node, char **arg)
{
	t_lst	*tmp;

	arg++;
	tmp = node;
	if (!*arg)
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else
	{
		while (*arg)
		{
			while (node)
			{
				if (ft_strcmp(node->name, *arg) == 0)
					node->line = NULL;
				node = node->next;
			}
			node = tmp;
			arg++;
		}
	}
	return (-1);
}
