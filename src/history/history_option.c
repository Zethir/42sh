/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:04:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/11 18:52:52 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int		option_c(t_shell *sh)
{
	char	*str;

	if (open("/tmp/history", O_WRONLY | O_TRUNC, 0644) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return (1);
	}
	str = ft_strdup(sh->hist->str);
	free_hist(sh->head);
	sh->head = NULL;
	sh->hist = init_hist(str);
	push_hist(&sh->head, sh->hist);
	free(str);
	return (0);
}

static int		do_option_bis(t_shell *sh, char **cmd, int fd)
{
	if (!cmd[2])
	{
		if (option_r(sh, fd) == 1)
			return (1);
	}
	else
	{
		ft_putendl_fd("Option [-r] doesn't need any arguments", 2);
		return (1);
	}
	return (0);
}

int				do_option(t_shell *sh, char **cmd, int fd)
{
	if (ft_strcmp(cmd[1], "-c") == 0)
	{
		if (option_c(sh) == 1)
			return (1);
	}
	else if (ft_strcmp(cmd[1], "-d") == 0)
	{
		if (!cmd[2])
		{
			ft_putendl_fd("Need entry number to execute", 2);
			return (1);
		}
		else
		{
			if (option_d(sh, cmd, fd) == 1)
				return (1);
		}
	}
	else if (ft_strcmp(cmd[1], "-r") == 0)
		if (do_option_bis(sh, cmd, fd) == 1)
			return (1);
	return (0);
}
