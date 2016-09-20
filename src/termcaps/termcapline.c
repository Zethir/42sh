/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 22:33:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/09 16:01:56 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static void	go_to_next_word(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 27 && info->buff[2] == 91
			&& info->buff[3] == 67)
	{
		while (node->str[node->i] && ft_isspace(node->str[node->i]) == 0)
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
			node->i++;
		}
		while (node->str[node->i] && ft_isspace(node->str[node->i]) == 1)
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
			node->i++;
		}
	}
	info->node = node;
}

static void	go_to_previous_word(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 27 && info->buff[2] == 91 &&
			info->buff[3] == 68)
	{
		while (node->i > 0 && ft_isspace(node->str[node->i]) == 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_int);
			node->i--;
		}
		while (node->i > 0 && ft_isspace(node->str[node->i]) == 1)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_int);
			node->i--;
		}
	}
	info->node = node;
}

static void	go_to_start_of_line(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 72)
	{
		while (node->i > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_int);
			node->i--;
		}
	}
	info->node = node;
}

void		go_to_end(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 70)
	{
		while (node->str[node->i])
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
			node->i++;
		}
	}
	info->node = node;
	go_to_start_of_line(info);
	go_to_previous_word(info);
	go_to_next_word(info);
}
