/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 22:33:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/18 17:13:56 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	go_to_next_word(t_hub *info, char *buff)
{
	if (NEXT_WORD)
	{
		while (info->node->str[info->node->i] &&
				ft_isspace(info->node->str[info->node->i]) == 0)
			info->node->i++;
		while (info->node->str[info->node->i] &&
				ft_isspace(info->node->str[info->node->i]) == 1)
			info->node->i++;
		prompt_print(info);
	}
}

void	go_to_previous_word(t_hub *info, char *buff)
{
	if (PREV_WORD)
	{
		while (info->node->i > 0 &&
				ft_isspace(info->node->str[info->node->i]) == 0)
			info->node->i--;
		while (info->node->i > 0 &&
				ft_isspace(info->node->str[info->node->i]) == 1)
			info->node->i--;
		prompt_print(info);
	}
}

void	go_to_start_of_line(t_hub *info, char *buff)
{
	if (HOME)
	{
		while (info->node->i > 0)
			info->node->i--;
		prompt_print(info);
	}
}

void	go_to_end(t_hub *info, char *buff)
{
	if (END)
	{
		while (info->node->str[info->node->i])
			info->node->i++;
		prompt_print(info);
	}
}
