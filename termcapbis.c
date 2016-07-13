/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:03:33 by cboussau          #+#    #+#             */
/*   Updated: 2016/05/31 17:53:06 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	deal_with_down(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 66 &&
			info->node->next)
	{
		tputs(tgetstr("rc", NULL), 1, ft_putchar_int);
		node->i = ft_strlen(node->str);
		tputs(tgetstr("ce", NULL), 1, ft_putchar_int);
		node = info->node->next;
		ft_putstr(node->str);
		node->i = ft_strlen(node->str);
		tputs(tgoto(tgetstr("ch", NULL), 0, node->i + 3), 1, ft_putchar_int);
	}
	info->node = node;
}

static void	deal_with_up(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 65
			&& info->node->prev)
	{
		tputs(tgetstr("rc", NULL), 1, ft_putchar_int);
		node->i = ft_strlen(node->str);
		tputs(tgetstr("ce", NULL), 1, ft_putchar_int);
		node = info->node->prev;
		ft_putstr(node->str);
		node->i = ft_strlen(node->str);
		tputs(tgoto(tgetstr("ch", NULL), 0, node->i + 3), 1, ft_putchar_int);
	}
	info->node = node;
}

void		deal_with_others(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 51
			&& node->str[node->i])
	{
		ft_memmove(node->str + node->i, node->str + node->i + 1,
				ft_strlen(node->str + node->i + 1) + 1);
		tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
	}
	if (info->buff[0] == 4 && info->buff[1] == -1 && info->buff[2] == 127)
	{	
		ft_putstr("exit\n");	
		exit(-1);
	}
	info->node = node;
	deal_with_up(info);
	deal_with_down(info);
}
