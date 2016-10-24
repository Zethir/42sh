/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:11:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 18:34:14 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int	deal_with_int(t_shell *sh, char **arg)
{
	int		i;

	i = 0;
	while ((*arg)[i])
	{
		if (*(arg)[i] < '0' || *(arg)[i] > '9')
		{
			ft_putendl_fd("exit: Badly formed number.", 2);
			return (-1);
		}
		i++;
	}
	reset_term(sh);
	exit(ft_atoi(*arg));
}

int			do_exit(t_shell *sh, char **arg)
{
	int		i;

	i = 0;
	arg++;
	if (!*arg)
	{
		reset_term(sh);
		exit(-1);
	}
	while (arg[i])
		i++;
	if (i > 1)
	{
		ft_putendl_fd("exit: Expression Syntax.", 2);
		return (-1);
	}
	else if (deal_with_int(sh, arg) == -1)
		return (-1);
	return (-1);
}
