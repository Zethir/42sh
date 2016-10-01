/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:25:42 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/01 17:12:58 by qdiaz            ###   ########.fr       */
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

	cmd = info->lex->cmd->argv[0];
	printf("info->lex->cmd->argv = %s\n", cmd);
	if (ft_strcmp(cmd, "env") == 0)
		deal_with_env(info, info->lex->cmd->argv);
	else if (ft_strcmp(cmd, "setenv") == 0)
		do_setenv(info->lst, info->lex->cmd->argv);
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		do_unsetenv(info->lst, info->lex->cmd->argv);
	else if (ft_strcmp(cmd, "cd") == 0)
		do_cd(info->lst, info->lex->cmd->argv);
	else if (ft_strcmp(cmd, "echo") == 0)
		do_echo(info->lex->cmd->argv);
	else if (ft_strcmp(cmd, "history") == 0)
		do_history(info, info->lex->cmd->argv);
	else if (ft_strncmp(cmd, "!", 1) == 0)
		do_designator(info, info->lex->cmd->argv);
	else if (ft_strcmp(cmd, "exit") == 0)
		do_exit(info->lex->cmd->argv);
	else if (ft_strcmp(cmd, "export") == 0)
		do_export(info);
	else
		return ;
}
