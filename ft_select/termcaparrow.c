/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 20:12:50 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/26 20:30:01 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	deal_with_left_sel(t_sel_struct *info, t_sel_lst *ptr)
{
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 68)
	{
		while (ptr->line != 1)
			ptr = ptr->next;
		ptr->line = 0;
		if (!ptr->prev)
		{
			ptr = info->node->tail;
			ptr->line = 1;
		}
		else
			left_arrow(info, ptr);
	}
}

static void	deal_with_right_sel(t_sel_struct *info, t_sel_lst *ptr)
{
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 67)
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

static void	deal_with_down_sel(t_sel_struct *info, t_sel_lst *ptr)
{
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 66)
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
			ptr->next->line = 1;
	}
}

static void	deal_with_up_sel(t_sel_struct *info, t_sel_lst *ptr)
{
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 65)
	{
		while (ptr->line != 1)
			ptr = ptr->next;
		ptr->line = 0;
		if (!ptr->prev)
		{
			ptr = info->node->tail;
			ptr->line = 1;
		}
		else
			ptr->prev->line = 1;
	}
}

void		deal_with_arrow_sel(t_sel_struct *info)
{
	t_sel_lst	*ptr;

	ptr = info->node->head;
	deal_with_up_sel(info, ptr);
	deal_with_down_sel(info, ptr);
	deal_with_left_sel(info, ptr);
	deal_with_right_sel(info, ptr);
}
