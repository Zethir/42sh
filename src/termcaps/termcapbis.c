/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcapbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:03:33 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 17:07:03 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void	deal_with_down(t_hub *info, char *buff)
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

static void	deal_with_up(t_hub *info, char *buff)
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

void		deal_with_others(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (DELETE && node->str[node->i])
	{
		ft_memmove(node->str + node->i, node->str + node->i + 1,
				ft_strlen(node->str + node->i + 1) + 1);
		tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
	}
	if (ESCAPE)
	{
		ft_putstr("exit\n");
		exit(-1);
	}
	info->node = node;
	deal_with_up(info, buff);
	deal_with_down(info, buff);
}
