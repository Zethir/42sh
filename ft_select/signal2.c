/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:55:11 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/26 20:53:13 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sigtstp_sel(int id)
{
	char			cp[2];
	t_sel_struct	*info;

	(void)id;
	info = NULL;
	info = stock_sel_struct(info, 1);
	cp[0] = info->term.c_cc[VSUSP];
	cp[1] = 0;
	info->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	clean_lst(info);
	tcsetattr(0, 0, &(info->term));
	tputs(tgetstr("te", NULL), 1, ft_putchar_int);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	ioctl(0, TIOCSTI, cp);
}

void	sigcont_sel(int id)
{
	t_sel_struct	*info;

	(void)id;
	info = NULL;
	info = stock_sel_struct(info, 1);
	init_sel_term(info);
	signal(SIGTSTP, ft_signal_sel);
	win_size(id);
}

void	sigint_sel(int id)
{
	t_sel_struct *info;

	(void)id;
	info = NULL;
	info = stock_sel_struct(info, 1);
	tcsetattr(0, TCSANOW, &(info->term));
	clean_lst(info);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	free_lst(info);
	exit(0);
}

void	ft_signal_sel(int id)
{
	(void)id;
	signal(SIGWINCH, win_size);
	signal(SIGCONT, sigcont_sel);
	signal(SIGTSTP, sigtstp_sel);
	signal(SIGINT, sigint_sel);
	signal(SIGQUIT, sigint_sel);
	signal(SIGTERM, sigint_sel);
}
