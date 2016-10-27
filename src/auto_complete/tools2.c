/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:47:38 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/27 19:51:40 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		my_tab(t_struct *info, t_lst *ptr)
{
	if (info->buff[0] == 9)
	{
		while (ptr->line != 1)
			ptr = ptr->next;
		ptr->line = 0;
		if (!ptr->next)
		{
			ptr = info->node->head;
			ptr->line = 1;
		}
		else
			right_arrow(info, ptr);
	}
}
