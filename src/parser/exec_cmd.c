/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:36:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 16:54:52 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	exec_cmd(t_env_hist *info)
{
	if (check_builtins(info->lex) == 1)
		do_builtins(info);
	else if ((info->parser->pid = fork()) == 0)
	{
		if (execve(info->parser->str, lex->cmd->argv, info->parser->env) < 0)
		{
			no_command_error(lex->cmd->argv[0]);
			exit (-1)
		}
	}
	else if (info->parser->pid < 0)
		exit (-1);
	wait(0);
}
