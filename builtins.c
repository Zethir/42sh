/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:25:42 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/23 17:51:08 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		check_builtins(t_struct *info)
{
	if (ft_strcmp(info->arg[0], "env") == 0)
		return (1);
	else if (ft_strcmp(info->arg[0], "setenv") == 0)
		return (1);
	else if (ft_strcmp(info->arg[0], "unsetenv") == 0)
		return (1);
	else if (ft_strcmp(info->arg[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(info->arg[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(info->arg[0], "history") == 0)
		return (1);
	else if (ft_strncmp(info->arg[0], "!", 1) == 0)
		return (1);
	return (0);
}

void	do_builtins(t_struct *info)
{
	if (ft_strcmp(info->arg[0], "env") == 0)
		deal_with_env(info, info->arg);
	else if (ft_strcmp(info->arg[0], "setenv") == 0)
		do_setenv(info->lst, info->arg);
	else if (ft_strcmp(info->arg[0], "unsetenv") == 0)
		do_unsetenv(info->lst, info->arg);
	else if (ft_strcmp(info->arg[0], "cd") == 0)
		do_cd(info->lst, info->arg);
	else if (ft_strcmp(info->arg[0], "echo") == 0)
		do_echo(info->arg);
	else if (ft_strcmp(info->arg[0], "history") == 0)
		do_history(info, info->arg);
	else if (ft_strncmp(info->arg[0], "!", 1) == 0)
		do_designator(info, info->arg);
}
