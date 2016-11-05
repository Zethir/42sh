/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:07:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/05 11:43:43 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	print_identifier_error(char *arg)
{
	ft_putstr_fd("42sh: export: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int		check_wrong_identifier(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < 'A' || arg[i] > 'Z')
			if (arg[i] < 'a' || arg[i] > 'z')
				if (arg[i] != '=')
				{
					print_identifier_error(arg);
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
