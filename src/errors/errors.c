/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:27:17 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 16:03:50 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	print_error_opt(char *arg)
{
	ft_putstr_fd("env: unsetenv ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": Invalid argument\n", 2);
}

void	print_error_arg(void)
{
	ft_putendl_fd("env: missing argument after option", 2);
	ft_putstr_fd("usage: env [-iv] [-P utilpath] [-S string] [-u name]\n", 2);
	ft_putstr_fd("           [name=value ...] [utility [argument ...]]\n", 2);
}

int		print_alpha_error(char **arg)
{
	int		i;
	char	*error;

	i = 0;
	error = "setenv: Variable name must contain alphanumeric characters.";
	while (arg[0][i])
	{
		if (arg[0][i] == '=')
		{
			ft_putendl_fd(error, 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	print_main_error(char *arg)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putendl_fd(arg, 2);
	ft_putstr_fd("usage: env [-iv] [-P utilpath] [-S string] [-u name]\n", 2);
	ft_putstr_fd("           [name=value ...] [utility [argument ...]]\n", 2);
}

void	print_parse_error(char c)
{
	ft_putstr_fd("42sh: parse error near `", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("'", 2);
}
