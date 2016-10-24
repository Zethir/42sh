/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:32:18 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 16:31:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		free_all_struct(t_shell *sh)
{
	if (sh->env)
		free_env(sh->env);
	if (sh->hist)
		free_hist(sh->hist);
	if (sh)
		free_shell(sh);
}

int			reset_term(t_shell *sh)
{
	stock_struct(sh, 1);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	if (tcgetattr(0, &(sh->term)) == -1)
		return (-1);
	sh->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(sh->term)) == -1)
		return (-1);
	free_all_struct(sh);
	return (0);
}

int			reset_term_no_free(t_shell *sh)
{
	stock_struct(sh, 1);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
	if (tcgetattr(0, &(sh->term)) == -1)
		return (-1);
	sh->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(sh->term)) == -1)
		return (-1);
	return (0);
}

int			init_term(t_shell *sh)
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
