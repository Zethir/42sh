/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:25:42 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/10 18:30:26 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		check_builtins(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "setenv") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "history") == 0)
		return (1);
	else if (ft_strncmp(cmd, "!", 1) == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

void	do_builtins(t_hub *info)
{
	char *cmd;

	cmd = info->parse->argv[0];
	if (ft_strcmp(cmd, "env") == 0)
		return (deal_with_env(info, info->parse->argv));
	else if (ft_strcmp(cmd, "setenv") == 0)
		return (do_setenv(info->lst, info->parse->argv));
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		return (do_unsetenv(info->lst, info->parse->argv));
	else if (ft_strcmp(cmd, "cd") == 0)
		return (do_cd(info->lst, info->parse->argv));
	else if (ft_strcmp(cmd, "echo") == 0)
		return (do_echo(info->parse->argv));
	else if (ft_strcmp(cmd, "history") == 0)
		return (do_history(info, info->parse->argv));
	else if (ft_strncmp(cmd, "!", 1) == 0)
		return (do_designator(info, info->parse->argv));
	else if (ft_strcmp(cmd, "exit") == 0)
		return (do_exit(info->parse->argv));
	else if (ft_strcmp(cmd, "export") == 0)
		return (do_export(info));
}
