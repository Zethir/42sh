/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:25:17 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/04 15:16:57 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

void	free_lst(t_struct *info)
{
	t_lst	*ptr;
	t_lst	*tmp;

	ptr = info->node->head;
	while (ptr)
	{
		if (ptr->name)
			free(ptr->name);
		if (ptr->save)
			free(ptr->save);
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	free(ptr);
	free(info->node);
	free(info);
	ptr = NULL;
	info->node = NULL;
	info = NULL;
}
