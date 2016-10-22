/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_multi_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:08:02 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 11:35:14 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	go_down_line(t_hub *info, char *buff)
{
	if (DOWN_CMD && ft_strlen(info->prompt->cmd) > info->prompt->win_size)
	{
		if ((size_t)info->prompt->i <= ft_strlen(info->prompt->cmd) -
				(info->prompt->win_size - 3))
			info->prompt->i = info->prompt->i + info->prompt->win_size;
		else
			info->prompt->i = ft_strlen(info->prompt->cmd);
		prompt_print(info, buff);
	}
}

void	go_up_line(t_hub *info, char *buff)
{
	if (UP_CMD && ft_strlen(info->prompt->cmd) > info->prompt->win_size)
	{
		info->prompt->i = info->prompt->i - info->prompt->win_size;
		prompt_print(info, buff);
	}
}
