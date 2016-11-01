/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:17:59 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/01 15:26:58 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

t_prompt	*stock_prompt(t_prompt *prompt, int i)
{
	static t_prompt *tmp = NULL;

	if (i == 0)
		tmp = prompt;
	return (tmp);
}

t_prompt	*init_prompt(void)
{
	t_prompt		*prompt;
	struct winsize	win;

	if (!(prompt = (t_prompt *)malloc(sizeof(t_prompt))))
		return (NULL);
	ft_bzero(prompt->cmd, 5000);
	prompt->i = 0;
	prompt->copy_mode = 0;
	prompt->cursor_start = 0;
	prompt->cursor_end = 0;
	prompt->copy_str = NULL;
	ioctl(0, TIOCGWINSZ, &win);
	prompt->win_size = win.ws_col;
	return (prompt);
}
