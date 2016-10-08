/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:36:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/08 15:32:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	exec_cmd(t_hub *info)
{
	init_parse(info);
	if (check_builtins(info->parse->argv[0]) == 1)
		do_builtins(info);
	else if ((info->parse->pid = fork()) == 0)
	{
		if (execve(info->parse->right_path, info->parse->argv, info->parse->env) < 0)
		{
			no_command_error(info->parse->argv[0]);
			exit (-1);
		}
	}
	else if (info->parse->pid < 0)
		exit (-1);
	wait(0);
}
