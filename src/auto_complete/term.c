/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:32:18 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/29 18:52:34 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_struct	*stock_select_struct(t_struct *info, int i)
{
	static t_struct *tmp = NULL;

	if (i == 0)
		tmp = info;
	return (tmp);
}

t_struct	*init_select_struct(char **argv)
{
	t_struct	*info;

	if (!(info = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	info->on = 0;
	info->node = init_lst(argv);
	info->node->head->line = 1;
	return (info);
}

void		win_select_size(int id)
{
	t_struct		*info;
	struct winsize	win;

	(void)id;
	info = NULL;
	info = stock_select_struct(info, 1);
	ioctl(0, TIOCGWINSZ, &win);
	info->col = win.ws_col;
	info->row = win.ws_row;
	longest_word(info);
	info->nb_item = (info->node->length) / info->nb_col;
	if (((info->node->length) % info->nb_col) != 0)
		info->nb_item += 1;
	check_size(info);
}
