/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 22:33:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/19 16:14:03 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	go_to_next_word(t_hub *info, char *buff)
{
	if (NEXT_WORD)
	{
		while (info->prompt->cmd[info->prompt->i] &&
				ft_isspace(info->prompt->cmd[info->prompt->i]) == 0)
			info->prompt->i++;
		while (info->prompt->cmd[info->prompt->i] &&
				ft_isspace(info->prompt->cmd[info->prompt->i]) == 1)
			info->prompt->i++;
		prompt_print(info, buff);
	}
}

void	go_to_previous_word(t_hub *info, char *buff)
{
	if (PREV_WORD)
	{
		while (info->prompt->i > 0 &&
				ft_isspace(info->prompt->cmd[info->prompt->i]) == 0)
			info->prompt->i--;
		while (info->prompt->i > 0 &&
				ft_isspace(info->prompt->cmd[info->prompt->i]) == 1)
			info->prompt->i--;
		prompt_print(info, buff);
	}
}

void	go_to_start_of_line(t_hub *info, char *buff)
{
	if (HOME)
	{
		while (info->prompt->i > 0)
			info->prompt->i--;
		prompt_print(info, buff);
	}
}

void	go_to_end(t_hub *info, char *buff)
{
	if (END)
	{
		while (info->prompt->cmd[info->prompt->i])
			info->prompt->i++;
		prompt_print(info, buff);
	}
}
