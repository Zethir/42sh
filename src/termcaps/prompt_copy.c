/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:37:07 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 18:28:50 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	start_copy_mode(t_prompt *prompt, char *buff)
{
	if (COPY_MODE && prompt->copy_mode == 1)
		prompt->copy_mode = 0;
	else if (COPY_MODE)
	{
		prompt->cursor_start = prompt->i;
		prompt->cursor_end = prompt->i;
		prompt->copy_mode = 1;
	}
}

void	copy_string(t_prompt *prompt, char *buff)
{
	if (COPY_STRING && prompt->copy_mode == 1)
	{
		prompt->copy_mode = 0;
		prompt->copy_str = ft_strsub(prompt->cmd, prompt->cursor_start,
				prompt->cursor_end - prompt->cursor_start + 1);
		prompt->cursor_start = 0;
		prompt->cursor_end = 0;
	}
}

void	cut_string(t_prompt *prompt, char *buff)
{
	int			len;

	if (CUT_STRING && prompt->copy_mode == 1)
	{
		prompt->copy_mode = 0;
		prompt->copy_str = ft_strsub(prompt->cmd, prompt->cursor_start,
				prompt->cursor_end - prompt->cursor_start + 1);
		len = ft_strlen(prompt->copy_str);
		while (len > 0 && prompt->i >= 0)
		{
			len--;
			prompt->i--;
		}
		prompt->i++;
		len = ft_strlen(prompt->copy_str);
		ft_memmove(prompt->cmd + prompt->i, prompt->cmd + prompt->i + len,
				ft_strlen(prompt->cmd + prompt->i + 1) + len);
		prompt->cursor_start = 0;
		prompt->cursor_end = 0;
		prompt_print(prompt, buff);
	}
}

void	paste_string(t_prompt *prompt, char *buff)
{
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(prompt->copy_str);
	if (PASTE_STRING && prompt->copy_str && prompt->copy_mode == 0 &&
			len + prompt->i < 4500)
	{
		ft_memmove(prompt->cmd + prompt->i + len, prompt->cmd + prompt->i,
				ft_strlen(prompt->cmd + prompt->i) + len);
		while (prompt->copy_str[i])
		{
			prompt->cmd[prompt->i] = prompt->copy_str[i];
			prompt->i++;
			i++;
		}
		prompt_print(prompt, buff);
	}
}
