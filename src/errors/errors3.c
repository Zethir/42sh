/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:07:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/23 10:29:38 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	print_identifier_error(t_hub *info, int i)
{
	ft_putstr_fd("21sh: export: ", 2);
	ft_putstr_fd(info->parse->argv[i], 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int		check_wrong_identifier(t_hub *info, int j)
{
	t_parse	*parse;
	int		i;

	i = 0;
	parse = info->parse;
	while (parse->argv[j][i])
	{
		if (parse->argv[j][i] < 'A' || parse->argv[j][i] > 'Z')
			if (parse->argv[j][i] < 'a' || parse->argv[j][i] > 'z')
				if (parse->argv[j][i] != '=')
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
