/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:36:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/21 20:36:31 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void	get_new_stdio(t_process *process)
{
	if (process->stdio[0] != 0)
		dup2(process->stdio[0], 0);
	if (process->stdio[1] != 1)
		dup2(process->stdio[1], 1);
	if (process->stdio[2] != 2)
		dup2(process->stdio[2], 2);
	if (process->closefd != -1)
		close(process->closefd);
}

void		launch_builtin(t_hub *info, t_process *process)
{
	int		save_stdio[3];
	int		ret;

	save_stdio[0] = dup(0);
	save_stdio[1] = dup(1);
	save_stdio[2] = dup(2);
	get_new_stdio(process);
	if ((ret = do_builtins(info)) == 0)
		process->completed = 1;
	dup2(save_stdio[0], 0);
	dup2(save_stdio[1], 1);
	dup2(save_stdio[2], 2);
}

void		launch_bin(t_hub *info, t_process *process)
{
	get_new_stdio(process);
	reset_term(info);
	if (execve(info->parse->right_path, info->parse->argv, info->parse->env) < 0)
	{
		ft_putstr("42sh: command not found: ");
		ft_putendl(info->parse->argv[0]);
		exit(1);
	}
}

void		exec_env(t_hub *info, char *arg, char **env_cpy)
{
	init_parse(info, arg);
	if (check_builtins(arg))
		do_builtins(info);
	else if ((info->parse->pid = fork()) == 0)
	{
		reset_term(info);
		if (execve(info->parse->right_path, info->parse->argv, env_cpy) < 0)
		{
			ft_putstr("42sh: command not found: ");
			ft_putendl(info->parse->argv[0]);
			exit(1);
		}
	}
	wait(0);
}

void		wait_for_process(t_process *process)
{
	int		status;
	
	status = 0;
	wait(&status);
	if (WIFEXITED(status) && status == 0)
		process->completed = 1;
	if (WIFEXITED(status) && status != 0)
		process->completed = 0;
	if (WIFSIGNALED(status))
		process->completed = 1;
}
