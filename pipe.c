/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 18:50:48 by cboussau          #+#    #+#             */
/*   Updated: 2016/06/03 18:05:19 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	exec_pipe_bis(t_struct *ptr, int pipefds[], int j, int i)
{
	char	*str;

	ptr->pid = fork();
	str = ft_strjoin(*ptr->right_path, ptr->arg[0]);
	if (ptr->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (ptr->cmd[i + 1])
			if (dup2(pipefds[j + 1], 1) < 0)
				exit(-1);
		if (j != 0)
			if (dup2(pipefds[j - 2], 0) < 0)
				exit(-1);
		close_pipefds(pipefds, ptr->num);
		if (check_for_chevron(ptr) == 1)
			deal_with_redirection(ptr);
		else if (execve(str, ptr->arg, ptr->env) < 0)
		{
			no_command_error(ptr->arg[0]);
			exit(-1);
		}
	}
	else if (ptr->pid < 0)
		exit(-1);
}

static void	exec_pipe(t_struct *info)
{
	int		pipefds[2 * info->num];
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (start_pipe(pipefds, info->num) == -1)
		exit(-1);
	while (info->cmd[i])
	{
		info->arg = ft_strsplit_ws(info->cmd[i]);
		if (access(ft_strjoin(*info->right_path, *info->arg), X_OK) != -1)
			exec_pipe_bis(info, pipefds, j, i);
		else
		{
			print_right_error(info->lst, info->arg[0]);
			return ;
		}
		j += 2;
		info->right_path++;
		i++;
	}
	close_pipefds(pipefds, info->num);
	wait_for_child(info->num);
}

static void	deal_with_path(t_struct *info, char **path)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	info->right_path = (char **)malloc(sizeof(char *) * ft_tablen(info->cmd));
	if (!info->right_path)
		return ;
	while (info->cmd[i])
	{
		info->arg = ft_strsplit_ws(info->cmd[i]);
		if (path && *info->arg && info->env)
		{
			info->right_path[i] = check_path(path, *info->arg);
			if (info->right_path[i])
				info->right_path[i] = ft_strjoin(info->right_path[i], "/");
			else
				info->right_path[i] = ft_strdup("");
		}
		else if (*info->arg && info->env)
			info->right_path[i] = ft_strdup("");
		j++;
		i++;
	}
}

int			deal_with_pipe(t_struct *info, char *arg)
{
	char		**path;

	info->cmd = ft_strsplit(arg, '|');
	info->num = ft_tablen(info->cmd) - 1;
	info->env = get_env(info->lst);
	if (!(path = (char **)malloc(sizeof(char *) * 7)))
		return (-1);
	path = split_path(info->lst);
	deal_with_path(info, path);
	exec_pipe(info);
	return (-1);
}
