/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:24:05 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 16:47:41 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		cd_prev(t_env *env)
{
	char	buf[512];
	char	*str;
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, "OLDPWD") == 0)
		{
			str = ft_strsub(ft_strchr(env->line, '='), 1, ft_strlen(env->line));
			if (getcwd(buf, 512) != NULL)
				change_varcontent(env, "OLDPWD", getcwd(buf, 512));
			chdir(str);
			free(str);
			change_varcontent(env, "PWD", getcwd(buf, 512));
		}
		env = env->next;
	}
	env = tmp;
}

static void		cd_home(t_env *env)
{
	char	buf[512];
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
		{
			if (getcwd(buf, 512) != NULL)
				change_varcontent(env, "OLDPWD", getcwd(buf, 512));
			chdir(env->home);
			change_varcontent(tmp, "PWD", getcwd(buf, 512));
		}
		env = env->next;
	}
	env = tmp;
}

static char		*go_to_dir_from_root(t_env *env, char **cmd)
{
	t_env	*tmp;
	char	*str;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
			chdir(env->home);
		env = env->next;
	}
	env = tmp;
	str = ft_strsub(cmd[1], 2, ft_strlen(cmd[1]));
	return (str);
}

static void		deal_with_cd_arg(t_env *env, char **cmd)
{
	struct stat	st;
	if (stat(cmd[1], &st) == -1)
	{
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": No such file or directory.\n", 2);
	}
	else if (!(S_ISDIR(st.st_mode)))
	{
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": Not a directory.\n", 2);
	}
	else if (access(cmd[1], X_OK) == -1)
	{
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": Permission denied.\n", 2);
	}
	else
		change_directory(env, cmd[1]);
}

int				do_cd(t_env *env, char **cmd)
{
	char	*tmp;

	if (!cmd[1] || (ft_strcmp(cmd[1], "~") == 0))
		cd_home(env);
	else if (cmd[1][0] == '~')
	{
		tmp = go_to_dir_from_root(env, cmd);
		free(cmd[1]);
		cmd[1] = ft_strdup(tmp);
		free(tmp);
		deal_with_cd_arg(env, cmd);
	}
	else if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("cd: Too many arguments.\n", 2);
		return (-1);
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
		cd_prev(env);
	else
		deal_with_cd_arg(env, cmd);
	return (0);
}
