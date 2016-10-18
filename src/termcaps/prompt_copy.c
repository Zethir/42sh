/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:37:07 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/18 19:37:36 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	start_copy_mode(t_hub *info, char *buff)
{
	t_prompt	*prompt;

	prompt = info->prompt;
	if (COPY_MODE && prompt->copy_mode == 1)
		prompt->copy_mode = 0;
	else if (COPY_MODE)
	{
		prompt->cursor_start = info->node->i;
		prompt->cursor_end = info->node->i;
		prompt->copy_mode = 1;
	}
	info->prompt = prompt;
}

void	copy_string(t_hub *info, char *buff)
{
	t_dlist		*node;
	t_prompt	*prompt;

	node = info->node;
	prompt = info->prompt;
	if (COPY_STRING && prompt->copy_mode == 1)
	{
		prompt->copy_mode = 0;
		prompt->copy_str = ft_strsub(node->str, prompt->cursor_start,
				prompt->cursor_end - prompt->cursor_start + 1);
		prompt->cursor_start = 0;
		prompt->cursor_end = 0;
	}
	info->node = node;
	info->prompt = prompt;
}

void	cut_string(t_hub *info, char *buff)
{
	int			len;

	if (CUT_STRING && info->prompt->copy_mode == 1)
	{
		info->prompt->copy_mode = 0;
		info->prompt->copy_str = ft_strsub(info->node->str,
				info->prompt->cursor_start, info->prompt->cursor_end -
				info->prompt->cursor_start + 1);
		len = ft_strlen(info->prompt->copy_str);
		while (len > 0 && info->node->i >= 0)
		{
			len --;
			info->node->i--;
		}
		info->node->i++;
		len = ft_strlen(info->prompt->copy_str);
		ft_memmove(info->node->str + info->node->i, info->node->str +
				info->node->i + len, ft_strlen(info->node->str + info->node->i
					+ 1) + len);
		info->prompt->cursor_start = 0;
		info->prompt->cursor_end = 0;
		prompt_print(info);
	}
}

void	paste_string(t_hub *info, char *buff)
{
	int			len;
	int			i;

	i = 0;
	if (PASTE_STRING && info->prompt->copy_str && info->prompt->copy_mode == 0)
	{
		len = ft_strlen(info->prompt->copy_str);
		if (len + info->node->i <= 300)
		{
			ft_memmove(info->node->str + info->node->i + len, info->node->str +
					info->node->i, ft_strlen(info->node->str + info->node->i) + len);
			while (info->prompt->copy_str[i])
			{
				info->node->str[info->node->i] = info->prompt->copy_str[i];
				info->node->i++;
				i++;
			}
			prompt_print(info);
		}
	}
}
