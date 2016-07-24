/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:02:17 by cboussau          #+#    #+#             */
/*   Updated: 2016/05/19 17:18:51 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_standout(t_lst *ptr)
{
	tputs(tgetstr("mr", NULL), 0, ft_putchar_int);
	ft_putstr_fd("\033[31m", 0);
	ft_putendl_fd(ptr->name, 0);
	ptr->select = 1;
	ft_putstr_fd("\e[00m", 0);
	ptr->save = ft_strdup(ptr->name);
	tputs(tgetstr("me", NULL), 0, ft_putchar_int);
}

static void	print_underline(t_lst *ptr, t_struct *info)
{
	tputs(tgetstr("us", NULL), 0, ft_putchar_int);
	if (info->buff[0] == ' ' && ptr->select == 0)
		print_standout(ptr);
	else if (info->buff[0] == ' ' && ptr->select == 1)
	{
		ft_putstr_fd("\033[1;34m", 0);
		ft_putendl_fd(ptr->name, 0);
		ft_putstr_fd("\e[00m", 0);
		bzero(ptr->save, ft_strlen(ptr->save));
		ptr->select = 0;
	}
	else if (ptr->select == 1)
		print_standout(ptr);
	else
	{
		ft_putstr_fd("\033[1;34m", 0);
		ft_putendl_fd(ptr->name, 0);
		ft_putstr_fd("\e[00m", 0);
	}
	tputs(tgetstr("ue", NULL), 0, ft_putchar_int);
}

void		print_opt(t_lst *ptr, t_struct *info)
{
	if (ptr->line == 1)
		print_underline(ptr, info);
	else if (ptr->select == 1)
		print_standout(ptr);
	else
	{
		ft_putstr_fd("\e[97m", 0);
		ft_putendl_fd(ptr->name, 0);
		ft_putstr_fd("\e[00m", 0);
	}
}
