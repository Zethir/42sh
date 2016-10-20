/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:03:33 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/19 16:28:32 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	deal_with_down(t_hub *info, char *buff)
{
	if (ARROW_DOWN && info->node->next)
	{
		info->node = info->node->next;
		info->prompt->cmd = info->node->str;
		info->prompt->i = ft_strlen(info->prompt->cmd);
		prompt_print(info, buff);
	}
}

void	deal_with_up(t_hub *info, char *buff)
{
	if (ARROW_UP && info->node->prev)
	{
		info->node = info->node->prev;
		info->prompt->cmd = info->node->str;
		info->prompt->i = ft_strlen(info->prompt->cmd);
		prompt_print(info, buff);
	}
}

void	deal_with_left(t_hub *info, char *buff)
{
	if (ARROW_LEFT && info->prompt->i > 0)
	{
		if (info->prompt->copy_mode == 1 &&
				info->prompt->i == info->prompt->cursor_start)
			info->prompt->cursor_start--;
		else if (info->prompt->copy_mode == 1 &&
				info->prompt->cursor_start < info->prompt->cursor_end)
			info->prompt->cursor_end--;
		info->prompt->i--;
		prompt_print(info, buff);
	}
}

void	deal_with_right(t_hub *info, char *buff)
{
	if (ARROW_RIGHT && info->prompt->cmd[info->prompt->i])
	{
		if (info->prompt->copy_mode == 1 &&
				info->prompt->i == info->prompt->cursor_end)
			info->prompt->cursor_end++;
		else if (info->prompt->copy_mode == 1 &&
				info->prompt->cursor_start < info->prompt->cursor_end)
			info->prompt->cursor_start++;
		info->prompt->i++;
		prompt_print(info, buff);
	}
}
