/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:07:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/26 18:14:06 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		check_number_bis(char **cmd)
{
	int	i;

	i = 2;
	while (cmd[0][i])
	{
		if (cmd[0][i] < '0' || cmd[0][i] > '9')
		{
			ft_putendl_fd("Only number are allowed after dash", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int		check_number(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[0][i])
	{
		if (cmd[0][i] < '0' || cmd[0][i] > '9')
		{
			ft_putendl_fd("Must choose between number and char", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int		check_alpha(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[0][i])
	{
		if (cmd[0][i] >= '0' && cmd[0][i] <= '9')
		{
			ft_putendl_fd("Must choose between number and char", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}
