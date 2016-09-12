/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:07:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/12 14:12:34 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

void	print_identifier_error(t_struct *info, int i)
{
	ft_putstr_fd("42sh: export: ", 2);
	ft_putstr_fd(info->arg[i], 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int		check_wrong_identifier(t_struct *info, int j)
{
	int	i;

	i = 0;
	while (info->arg[j][i])
	{
		if (info->arg[j][i] < 'A' || info->arg[j][i] > 'Z')
			if (info->arg[j][i] < 'a' || info->arg[j][i] > 'z')
				if (info->arg[j][i] != '=')
				{
					print_identifier_error(info, j);
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
