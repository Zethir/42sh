/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 22:33:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 13:52:05 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	go_to_next_word(t_prompt *prompt, char *buff)
{
	if (NEXT_WORD)
	{
		while (prompt->cmd[prompt->i] &&
				ft_isspace(prompt->cmd[prompt->i]) == 0)
			prompt->i++;
		while (prompt->cmd[prompt->i] &&
				ft_isspace(prompt->cmd[prompt->i]) == 1)
			prompt->i++;
		prompt_print(prompt, buff);
	}
}

void	go_to_previous_word(t_prompt *prompt, char *buff)
{
	if (PREV_WORD)
	{
		while (prompt->i > 0 &&
				ft_isspace(prompt->cmd[prompt->i]) == 0)
			prompt->i--;
		while (prompt->i > 0 &&
				ft_isspace(prompt->cmd[prompt->i]) == 1)
			prompt->i--;
		prompt_print(prompt, buff);
	}
}

void	go_to_start_of_line(t_prompt *prompt, char *buff)
{
	if (HOME)
	{
		while (prompt->i > 0)
			prompt->i--;
		prompt_print(prompt, buff);
	}
}

void	go_to_end(t_prompt *prompt, char *buff)
{
	if (END)
	{
		while (prompt->cmd[prompt->i])
			prompt->i++;
		prompt_print(prompt, buff);
	}
}
