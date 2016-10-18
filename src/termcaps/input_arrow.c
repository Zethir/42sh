/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:03:33 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/18 19:26:40 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	deal_with_down(t_hub *info, char *buff)
{
	if (ARROW_DOWN && info->node->next)
	{
		info->node = info->node->next;
		info->node->i = ft_strlen(info->node->str);
		prompt_print(info);
	}
}

void	deal_with_up(t_hub *info, char *buff)
{
	if (ARROW_UP && info->node->prev)
	{
		info->node = info->node->prev;
		info->node->i = ft_strlen(info->node->str);
		prompt_print(info);
	}
}

void	deal_with_left(t_hub *info, char *buff)
{
	if (ARROW_LEFT && info->node->i > 0)
	{
		if (info->prompt->copy_mode == 1 &&
				info->node->i == info->prompt->cursor_start)
			info->prompt->cursor_start--;
		else if (info->prompt->copy_mode == 1 &&
				info->prompt->cursor_start < info->prompt->cursor_end)
			info->prompt->cursor_end--;
		info->node->i--;
		prompt_print(info);
	}
}

void	deal_with_right(t_hub *info, char *buff)
{
	if (ARROW_RIGHT && info->node->str[info->node->i])
	{
		if (info->prompt->copy_mode == 1 &&
				info->node->i == info->prompt->cursor_end)
			info->prompt->cursor_end++;
		else if (info->prompt->copy_mode == 1 &&
				info->prompt->cursor_start < info->prompt->cursor_end)
			info->prompt->cursor_start++;
		info->node->i++;
		prompt_print(info);
	}
}
