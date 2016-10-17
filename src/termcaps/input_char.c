/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:28:53 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/17 16:39:03 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void		deal_with_delete(t_hub *info, char *buff)
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
}

void	deal_with_backspace(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (BACK_SPACE && node->i > 0)
	{
		node->i--;
		ft_memmove(node->str + node->i, node->str + node->i + 1,
				ft_strlen(node->str + node->i + 1) + 1);
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
		tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

void	deal_with_space(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (WHITE_SPACE)
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

void		deal_with_charac(t_hub *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (CHARACTERE)
	{
		ft_memmove(node->str + node->i + 1, node->str + node->i,
				ft_strlen(node->str + node->i) + 1);
		node->str[node->i] = *buff;
		node->i++;
		tputs(tgetstr("im", NULL), 1, ft_putchar_int);
		write(1, &buff[0], 1);
		tputs(tgetstr("ei", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}
