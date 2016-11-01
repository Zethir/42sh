/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_multi_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:08:02 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/01 15:00:41 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	go_down_line(t_prompt *prompt, char *buff)
{
	if (DOWN_CMD && ft_strlen(prompt->cmd) > prompt->win_size)
	{
		if ((size_t)prompt->i <= ft_strlen(prompt->cmd) -
				(prompt->win_size - 3))
			prompt->i = prompt->i + prompt->win_size;
		else
			prompt->i = ft_strlen(prompt->cmd);
		prompt_print(prompt, 1);
	}
}

void	go_up_line(t_prompt *prompt, char *buff)
{
	if (UP_CMD && ft_strlen(prompt->cmd) > prompt->win_size)
	{
		prompt->i = prompt->i - prompt->win_size;
		prompt_print(prompt, 1);
	}
}
