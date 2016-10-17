/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 22:33:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/17 16:40:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	go_to_next_word(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (NEXT_WORD)
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

void	go_to_previous_word(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (PREV_WORD)
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

void	go_to_start_of_line(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (HOME)
	{
		while (node->i > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_int);
			node->i--;
		}
	}
	info->node = node;
}

void	go_to_end(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (END)
	{
		while (node->str[node->i])
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
			node->i++;
		}
	}
	info->node = node;
}
