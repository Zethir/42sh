/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:03:33 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/17 16:38:05 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	deal_with_down(t_hub *info, char *buff)
{
	if (ARROW_DOWN && info->node->next)
	{
		tputs(tgetstr("rc", NULL), 1, ft_putchar_int);
		info->node->i = ft_strlen(info->node->str);
		tputs(tgetstr("ce", NULL), 1, ft_putchar_int);
		info->node = info->node->next;
		ft_putstr(info->node->str);
		info->node->i = ft_strlen(info->node->str);
		tputs(tgoto(tgetstr("ch", NULL), 0, info->node->i + 3), 1,
				ft_putchar_int);
	}
}

void	deal_with_up(t_hub *info, char *buff)
{
	if (ARROW_UP && info->node->prev)
	{
		tputs(tgetstr("rc", NULL), 1, ft_putchar_int);
		info->node->i = ft_strlen(info->node->str);
		tputs(tgetstr("ce", NULL), 1, ft_putchar_int);
		info->node = info->node->prev;
		ft_putstr(info->node->str);
		info->node->i = ft_strlen(info->node->str);
		tputs(tgoto(tgetstr("ch", NULL), 0, info->node->i + 3), 1,
				ft_putchar_int);
	}
}

void	deal_with_arrow(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (ARROW_LEFT && node->i > 0)
	{
		node->i--;
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	}
	if (ARROW_RIGHT && node->str[node->i])
	{
		node->i++;
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}
