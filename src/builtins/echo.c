/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 14:55:27 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/10 18:23:37 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		print_echo(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\"' || cmd[i] == '\'')
			i++;
		ft_putchar(cmd[i]);
		i++;
	}
}

int				do_echo(char **cmd)
{
	int i;
	int cnt;

	i = 1;
	cnt = 0;
	if (!cmd[1])
		ft_putchar('\n');
	else
	{
		if (cmd[1] && ft_strcmp(cmd[1], "-n") != 0)
			cnt = 1;
		while (cmd[i])
		{
			print_echo(cmd[i]);
			if (cmd[i + 1])
				ft_putchar(' ');
			i++;
		}
		if (cnt == 1)
			ft_putchar('\n');
	}
	return (0);
}
