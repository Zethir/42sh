/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:07:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 18:22:55 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	print_identifier_error(t_lex *lex, int i)
{
	ft_putstr_fd("42sh: export: ", 2);
	ft_putstr_fd(lex->cmd->argv[i], 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int		check_wrong_identifier(t_lex *lex, int j)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = lex->cmd;
	while (cmd->argv[j][i])
	{
		if (cmd->argv[j][i] < 'A' || cmd->argv[j][i] > 'Z')
			if (cmd->argv[j][i] < 'a' || cmd->argv[j][i] > 'z')
				if (cmd->argv[j][i] != '=')
				{
					print_identifier_error(lex, j);
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
