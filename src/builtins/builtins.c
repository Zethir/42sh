/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:25:42 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 14:49:36 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int			check_builtins(char *cmd)
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
	else if (ft_strchr(cmd, '=') != NULL)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else
		return (0);
}

static int	do_builtins_bis(t_shell *sh, t_parse *parse, char *cmd)
{
	if (ft_strcmp(cmd, "history") == 0)
		return (do_history(sh, parse->argv));
	else if (ft_strncmp(cmd, "!", 1) == 0)
		return (do_designator(sh, parse->argv));
	else if (ft_strcmp(cmd, "exit") == 0)
		return (do_exit(sh, parse->argv));
	else if (ft_strcmp(cmd, "export") == 0)
		return (do_export(sh->env, parse->argv));
	else if (ft_strchr(cmd, '=') != NULL)
		return (create_new_variable(sh->env, parse->argv));
	else if (ft_strcmp(cmd, "unset") == 0)
		return (do_unsetenv(sh->env, parse->argv, 1));
	else
		return (-1);
}

int			do_builtins(t_shell *sh, t_parse *parse)
{
	char *cmd;

	cmd = parse->argv[0];
	if (ft_strcmp(cmd, "env") == 0)
		return (deal_with_env(sh, parse->argv));
	else if (ft_strcmp(cmd, "setenv") == 0)
		return (do_setenv(sh->env, parse->argv));
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		return (do_unsetenv(sh->env, parse->argv, 0));
	else if (ft_strcmp(cmd, "cd") == 0)
		return (do_cd(sh->env, parse->argv));
	else if (ft_strcmp(cmd, "echo") == 0)
		return (do_echo(parse->argv));
	else
		return (do_builtins_bis(sh, parse, cmd));
}
