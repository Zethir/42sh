/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:36:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/01 15:43:40 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	exec_cmd(t_hub *info)
{
	t_cmd	*cmd;

	cmd = info->lex->cmd;
	if (check_builtins(cmd->argv[0]) == 1)
		do_builtins(info);
	else if ((info->parse->pid = fork()) == 0)
	{
		if (execve(info->parse->bin_path, cmd->argv, info->parse->env) < 0)
		{
			no_command_error(cmd->argv[0]);
			exit (-1);
		}
	}
	else if (info->parse->pid < 0)
		exit (-1);
	wait(0);
}
