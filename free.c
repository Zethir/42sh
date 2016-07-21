/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/20 17:16:14 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	free_list(t_lst *node)
{
	while (node)
	{
		if (node->line)
			ft_strdel(&node->line);
		if (node->name)
			ft_strdel(&node->name);
		node = node->next;
	}
	free(node);
	node = NULL;
}

void	free_dlist(t_dlist *node)
{
	while (node)
	{
		if (node->str)
			ft_strdel(&node->str);
		node = node->next;
	}
	free(node);
	node = NULL;
}
