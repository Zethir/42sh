/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:36:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/31 18:34:39 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

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

void		launch_builtin(t_shell *sh, t_parse *parse, t_job *job)
{
	int		save_stdio[3];
	int		ret;

	save_stdio[0] = dup(0);
	save_stdio[1] = dup(1);
	save_stdio[2] = dup(2);
	get_new_stdio(job->process);
	if ((ret = do_builtins(sh, job, parse)) == 0)
		job->process->completed = 1;
	dup2(save_stdio[0], 0);
	dup2(save_stdio[1], 1);
	dup2(save_stdio[2], 2);
}

void		launch_bin(t_shell *sh, t_parse *parse, t_job *job)
{
	get_new_stdio(job->process);
	reset_term_no_free(sh);
	if (execve(parse->right_path, parse->argv, parse->env) < 0)
	{
		ft_putstr("42sh: command not found: ");
		ft_putendl(parse->argv[0]);
		exit(1);
	}
}

void		exec_env(t_shell *sh, char *arg, char **env_cpy)
{
	t_parse		*parse;
	t_job		*job;

	parse = init_parse(sh, arg);
	job = NULL;
	if (check_builtins(arg))
		do_builtins(sh, job, parse);
	else if ((parse->pid = fork()) == 0)
	{
		reset_term_no_free(sh);
		if (execve(parse->right_path, parse->argv, env_cpy) < 0)
		{
			ft_putstr("42sh: command not found: ");
			ft_putendl(parse->argv[0]);
			exit(1);
		}
	}
	wait(0);
	free_parse(&parse);
}
