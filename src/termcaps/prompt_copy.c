/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:37:07 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/17 19:36:36 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	start_copy_mode(t_hub *info, char *buff)
{
	t_prompt	*prompt;

	prompt = info->prompt;
	if (COPY_MODE && prompt->copy_mode == 1)
	{
		prompt->copy_mode = 0;
	}
	else if (COPY_MODE)
	{
		prompt->cursor_start = info->node->i;
		prompt->copy_mode = 1;
	}
	info->prompt = prompt;
}

void	copy_string(t_hub *info, char *buff)
{
	t_dlist		*node;
	t_prompt	*prompt;
	int			swap;

	node = info->node;
	prompt = info->prompt;
	if (COPY_STRING && prompt->copy_mode == 1)
	{
		prompt->copy_mode = 0;
		prompt->cursor_end = node->i;
		if (prompt->cursor_start > prompt->cursor_end)
		{
			swap = prompt->cursor_start;
			prompt->cursor_start = prompt->cursor_end;
			prompt->cursor_end = swap;
		}
		prompt->copy_str = ft_strsub(node->str, prompt->cursor_start,
				prompt->cursor_end - prompt->cursor_start + 1);
	}
	info->node = node;
	info->prompt = prompt;
}

void	cut_string(t_hub *info, char *buff)
{
	t_dlist		*node;
	t_prompt	*prompt;
	int			swap;
	int			len;

	node = info->node;
	prompt = info->prompt;
	if (CUT_STRING && prompt->copy_mode == 1)
	{
		prompt->copy_mode = 0;
		prompt->cursor_end = node->i;
		if (prompt->cursor_start > prompt->cursor_end)
		{
			swap = prompt->cursor_start;
			prompt->cursor_start = prompt->cursor_end;
			prompt->cursor_end = swap;
		}
		prompt->copy_str = ft_strsub(node->str, prompt->cursor_start,
				prompt->cursor_end - prompt->cursor_start + 1);
		len = ft_strlen(prompt->copy_str);
		while (len > 0 && node->i >= 0)
		{
			tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
			if (node->i > 0)
			tputs(tgetstr("le", NULL), 1, ft_putchar_int);
			node->i--;
			len--;
		}
		node->i++;
		len = ft_strlen(prompt->copy_str);
		ft_memmove(node->str + node->i, node->str + node->i + len,
				ft_strlen(node->str + node->i + 1) + len);
	}
	info->node = node;
	info->prompt = prompt;
}

void	paste_string(t_hub *info, char *buff)
{
	t_dlist		*node;
	t_prompt	*prompt;
	int			len;
	int			i;

	node = info->node;
	prompt = info->prompt;
	i = 0;
	if (PASTE_STRING && prompt->copy_str && prompt->copy_mode == 0)
	{
		len = ft_strlen(prompt->copy_str);
		ft_memmove(node->str + node->i + len, node->str + node->i,
				ft_strlen(node->str + node->i) + len);
		tputs(tgetstr("im", NULL), 1, ft_putchar_int);
		tputs(tgetstr("me", NULL), 1, ft_putchar_int);
		while (prompt->copy_str[i])
		{
			ft_putchar(prompt->copy_str[i]);
			node->str[node->i] = prompt->copy_str[i];
			node->i++;
			i++;
		}
		tputs(tgetstr("ei", NULL), 1, ft_putchar_int);
	}
	info->node = node;
	info->prompt = prompt;
}
