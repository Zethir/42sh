/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:32:18 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/11 17:58:40 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	win_size(int id)
{
	t_prompt		*prompt;
	struct winsize	win;

	(void)id;
	prompt = NULL;
	prompt = stock_prompt(prompt, 1);
	ioctl(0, TIOCGWINSZ, &win);
	prompt->win_size = win.ws_col;
	prompt_print(prompt, 1);
}

int		reset_term(t_shell *sh)
{
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	if (tcgetattr(0, &(sh->term)) == -1)
		return (-1);
	sh->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(sh->term)) == -1)
		return (-1);
	free_shell(sh);
	return (0);
}

int		reset_term_no_free(t_shell *sh)
{
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	if (tcgetattr(0, &(sh->term)) == -1)
		return (-1);
	sh->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(sh->term)) == -1)
		return (-1);
	return (0);
}

int		init_term(t_shell *sh)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) != 1)
		return (-1);
	if (tcgetattr(0, &(sh->term)) == -1)
		return (-1);
	sh->term.c_lflag &= ~(ICANON | ECHO);
	sh->term.c_cc[VMIN] = 1;
	sh->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(sh->term)) == -1)
		return (-1);
	return (0);
}
