/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:55:11 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/22 14:25:17 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	sigtstp(int id)
{
	char		cp[2];
	t_env_hist	*info;

	(void)id;
	info = NULL;
	info = stock_struct(info, 1);
	cp[0] = info->term.c_cc[VSUSP];
	cp[1] = 0;
	info->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	tcsetattr(0, 0, &(info->term));
	ioctl(0, TIOCSTI, cp);
}

void	sigcont(int id)
{
	t_env_hist	*info;

	(void)id;
	info = NULL;
	info = stock_struct(info, 1);
	init_term(info);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	get_prompt(info->lst);
	signal(SIGTSTP, ft_signal);
}

void	sigint(int id)
{
	t_env_hist	*info;

	(void)id;
	info = NULL;
	info = stock_struct(info, 1);
	if (info->pid != 0)
	{
		ft_putchar('\n');
		get_prompt(info->lst);
	}
}

void	sigquit(int id)
{
	t_env_hist *info;

	(void)id;
	info = NULL;
	info = stock_struct(info, 1);
	tcsetattr(0, TCSANOW, &(info->term));
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	free_list(info->lst);
	exit(0);
}

void	ft_signal(int id)
{
	(void)id;
	signal(SIGCONT, sigcont);
	signal(SIGTSTP, sigtstp);
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
	signal(SIGTERM, sigquit);
}
