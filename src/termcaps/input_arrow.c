/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:03:33 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/26 18:18:06 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	deal_with_down(t_hist *hist, t_prompt *prompt, char *buff)
{
	if (ARROW_DOWN && hist->next)
	{
		hist = hist->next;
		if (!hist->str)
			hist->str = ft_strdup("");
		ft_strcpy(prompt->cmd, hist->str);
		prompt->i = ft_strlen(prompt->cmd);
		prompt_print(prompt, buff);
	}
}

void	deal_with_up(t_hist *hist, t_prompt *prompt, char *buff)
{
	if (ARROW_UP && hist->prev)
	{
		hist = hist->prev;
		ft_strcpy(prompt->cmd, hist->str);
		prompt->i = ft_strlen(prompt->cmd);
		prompt_print(prompt, buff);
	}
}

void	deal_with_left(t_prompt *prompt, char *buff)
{
	if (ARROW_LEFT && prompt->i > 0)
	{
		if (prompt->copy_mode == 1 && prompt->i == prompt->cursor_start)
			prompt->cursor_start--;
		else if (prompt->copy_mode == 1 &&
				prompt->cursor_start < prompt->cursor_end)
			prompt->cursor_end--;
		prompt->i--;
		prompt_print(prompt, buff);
	}
}

void	deal_with_right(t_prompt *prompt, char *buff)
{
	if (ARROW_RIGHT && prompt->cmd[prompt->i])
	{
		if (prompt->copy_mode == 1 && prompt->i == prompt->cursor_end)
			prompt->cursor_end++;
		else if (prompt->copy_mode == 1 &&
				prompt->cursor_start < prompt->cursor_end)
			prompt->cursor_start++;
		prompt->i++;
		prompt_print(prompt, buff);
	}
}
