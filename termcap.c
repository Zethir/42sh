/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:36:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/23 17:07:57 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	deal_with_backspace(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (*info->buff == 127 && node->i > 0)
	{
		node->i--;
		ft_memmove(node->str + node->i, node->str + node->i + 1,
				ft_strlen(node->str + node->i + 1) + 1);
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
		tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

static void	deal_with_space(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (*info->buff == ' ')
	{
		ft_memmove(node->str + node->i + 1, node->str + node->i,
				ft_strlen(node->str + node->i) + 1);
		node->str[node->i] = ' ';
		node->i++;
		tputs(tgetstr("im", NULL), 1, ft_putchar_int);
		ft_putchar(' ');
		tputs(tgetstr("ei", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

static void	deal_with_arrow(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 68
			&& node->i > 0)
	{
		node->i--;
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	}
	if (info->buff[0] == 27 && info->buff[1] == 91 && info->buff[2] == 67
			&& node->str[node->i])
	{
		node->i++;
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

static void	deal_with_charac(t_struct *info)
{
	t_dlist		*node;

	node = info->node;
	if (*info->buff >= '!' && *info->buff <= '~')
	{
		ft_memmove(node->str + node->i + 1, node->str + node->i,
				ft_strlen(node->str + node->i) + 1);
		node->str[node->i] = *info->buff;
		node->i++;
		tputs(tgetstr("im", NULL), 1, ft_putchar_int);
		write(1, &info->buff[0], 1);
		tputs(tgetstr("ei", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

char		*deal_with_termcap(t_struct *info)
{
	int			ret;
	
	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	while ((ret = read(0, info->buff, BUFF_SIZE) != -1))
	{
		deal_with_charac(info);
		deal_with_others(info);
		deal_with_space(info);
		deal_with_backspace(info);
		deal_with_arrow(info);
		go_to_end(info);
		if (*info->buff == 10 && info->node->str)
		{
			if (info->node->next)
				go_to_end_list(info);
			break;
		}
		if (*info->buff == 9 && info->node->str != NULL)
			tab_completion(info, info->node->str);
	}
	return (info->node->str);
}
