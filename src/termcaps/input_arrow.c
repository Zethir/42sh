/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:03:33 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/01 14:58:51 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	deal_with_down(t_shell *sh, t_prompt *prompt, char *buff)
{
	if (ARROW_DOWN && sh->hist->next)
	{
		sh->hist = sh->hist->next;
		if (!sh->hist->str)
			sh->hist->str = ft_strdup("");
		ft_strcpy(prompt->cmd, sh->hist->str);
		prompt->i = ft_strlen(prompt->cmd);
		prompt_print(prompt, 1);
	}
}

void	deal_with_up(t_shell *sh, t_prompt *prompt, char *buff)
{
	if (ARROW_UP && sh->hist->prev)
	{
		sh->hist = sh->hist->prev;
		ft_strcpy(prompt->cmd, sh->hist->str);
		prompt->i = ft_strlen(prompt->cmd);
		prompt_print(prompt, 1);
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
		prompt_print(prompt, 1);
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
		prompt_print(prompt, 1);
	}
}
