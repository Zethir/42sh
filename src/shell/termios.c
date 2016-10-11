/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:32:18 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/11 18:18:11 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int			reset_term(t_hub *info)
{
	if (tcgetattr(0, &(info->term)) == -1)
		return (-1);
	info->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(info->term)) == -1)
		return (-1);
	return (0);
}

int			init_term(t_hub *info)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) != 1)
		return (-1);
	if (tcgetattr(0, &(info->term)) == -1)
		return (-1);
	info->term.c_lflag &= ~(ICANON | ECHO);
	info->term.c_cc[VMIN] = 1;
	info->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(info->term)) == -1)
		return (-1);
	return (0);
}
