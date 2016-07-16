/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:40:36 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/16 15:32:50 by qdiaz            ###   ########.fr       */
/*   Updated: 2016/07/14 17:31:48 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	do_argbis(t_struct *info, char *arg, char **cmd)
{
	int		i;

	i = 0;
	if (ft_strcmp(*cmd, "exit") == 0)
		i = do_exit(arg);
	else if (ft_strcmp(*cmd, "env") == 0)
		i = deal_with_env(info, arg);
	else if (ft_strcmp(*cmd, "setenv") == 0)
		i = do_setenv(info->lst, arg);
	else if (ft_strcmp(*cmd, "unsetenv") == 0)
		i = do_unsetenv(info->lst, arg);
	else if (ft_strcmp(*cmd, "cd") == 0)
		i = do_cd(info->lst, arg);
	else if (ft_strcmp(*cmd, "echo") == 0)
		i = do_echo(cmd);
	else if (ft_strcmp(*cmd, "history") == 0)
		i = do_history(info, cmd);
	else if (*cmd)
		i = deal_with_pipe(info, arg);
	return (i);
}

static int	do_arg(t_struct *info, char *arg)
{
	int		i;
	char	**cmd;
	char	*line;

	i = 0;
	while (check_for_parenth(arg) != 0)
	{
		get_prompt(info->lst);
		line = deal_with_termcap(info);
		ft_putchar('\n');
		arg = ft_strjoin(arg, line);
	}
	if (!(cmd = ft_strsplit_ws(arg)))
		return (0);
	i = do_argbis(info, arg, cmd);
	ft_strdel(cmd);
	return (i);
}

static int	mainbis_21sh(t_struct *info)
{
	char		*line;
	char		**arg;

	line = deal_with_termcap(info);
	ft_putchar('\n');
	add_history(info, line);
	if (!line)
		return (-1);
	arg = ft_strsplit(line, ';');
	while (*arg)
	{
		if (do_arg(info, *arg) >= 0)
		{
			ft_putstr("exit\n");
			free(line);
			ft_strdel(arg);
			return (-1);
		}
		arg++;
	}
	return (0);
}

static void	main_21sh(char **env)
{
	t_struct	*info;

	info = init_struct(env);
	while (1)
	{
		if (check_lst(info->lst) == 0)
			info->lst = init_lst(env);
		get_prompt(info->lst);
		stock_struct(info, 0);
		if (mainbis_21sh(info) == -1)
			break ;
		push_node_bis(&info->node, create_node());
		info->node = info->node->next;
	}
	if (reset_term(info) == -1)
		return ;
	if (info->lst)
		free_list(info->lst);
}

int			main(int argc, char **argv, char **env)
{
	int				id;

	argv = NULL;
	id = 0;
	signal(SIGINT, SIG_IGN);
	ft_signal(id);
	if (argc == 1)
		main_21sh(env);
	else
		return (1);
	return (0);
}
