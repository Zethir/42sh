/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:07:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/10 12:36:15 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

void	print_identifier_error(t_struct *info)
{
	ft_putstr_fd("42sh: export: ", 2);
	ft_putstr_fd(info->arg[1], 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int		check_wrong_identifier(t_struct *info)
{
	int	i;

	i = 0;
	while (info->arg[1][i])
	{
		if (info->arg[1][i] < 'A' || info->arg[1][i] > 'Z')
			if (info->arg[1][i] < 'a' || info->arg[1][i] > 'z')
				if (info->arg[1][i] != '=')
				{
					print_identifier_error(info);
					return (1);
				}
		i++;
	}
	return (0);
}

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
