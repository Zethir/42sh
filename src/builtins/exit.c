/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:11:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/19 16:36:37 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int	deal_with_int(char **arg)
{
	int		i;

	i = 0;
	while ((*arg)[i])
	{
		if ((*arg)[i] < '0' || (*arg)[i] > '9')
		{
			ft_putendl_fd("exit: Badly formed number.", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int			do_exit(t_hub *info, char **arg)
{
	int		i;

	i = 0;
	arg++;
	if (!*arg)
	{
		reset_term(info);
		exit(-1);
	}
	while (arg[i])
		i++;
	if (i > 1)
	{
		ft_putendl_fd("exit: Expression Syntax.", 2);
		return (-1);
	}
	if (*arg[0] >= '0' && *arg[0] <= '9')
	{
		if (deal_with_int(arg) == 0)
		{
			reset_term(info);
			exit(-1);
		}
		else
			return (-1);
	}
	reset_term(info);
	exit(-1);
}
