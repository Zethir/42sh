/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:40:36 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/26 17:49:34 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	do_arg(t_struct *info, char *arg)
{
	char	*line;
	char	**cmd;

	while (check_for_parenth(arg) != 0)
	{
		get_prompt(info->lst);
		line = deal_with_termcap(info);
		ft_putchar('\n');
		arg = ft_strjoin(arg, line);
	}
	cmd = ft_strsplit_ws(arg);
	if (ft_strcmp(cmd[0], "exit") == 0)
		do_exit(cmd);
	deal_with_pipe(info, arg);
	return (-1);
}

static int	mainbis_21sh(t_struct *info)
{
	char		*line;
	char		**arg;

	line = deal_with_termcap(info);
	ft_putchar('\n');
	if (!line)
		return (-1);
	add_history(info);
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
