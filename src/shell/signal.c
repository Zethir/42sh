/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:55:11 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 18:35:44 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	sigtstp(int id)
{
	char	cp[2];
	t_shell	*sh;

	(void)id;
	sh = NULL;
	sh = stock_struct(sh, 1);
	cp[0] = sh->term.c_cc[VSUSP];
	cp[1] = 0;
	sh->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	tcsetattr(0, 0, &(sh->term));
	ioctl(0, TIOCSTI, cp);
}

void	sigcont(int id)
{
	t_shell	*sh;

	(void)id;
	sh = NULL;
	sh = stock_struct(sh, 1);
	init_term(sh);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	get_prompt(sh->env);
	color(RED, "$> ");
	color(RESET, "");
	signal(SIGTSTP, ft_signal);
}

void	sigint(int id)
{
	t_shell	*sh;

	(void)id;
	sh = NULL;
	sh = stock_struct(sh, 1);
	ft_putchar('\n');
	get_prompt(sh->env);
	color(RED, "$> ");
	color(RESET, "");
}

void	sigquit(int id)
{
	t_shell *sh;

	(void)id;
	sh = NULL;
	reset_term(sh);
	exit(0);
}

void	ft_signal(int id)
{
	(void)id;
	signal(SIGWINCH, win_size);
	signal(SIGCONT, sigcont);
	signal(SIGTSTP, sigtstp);
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
	signal(SIGTERM, sigquit);
}
