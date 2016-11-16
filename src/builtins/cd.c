/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:24:05 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/16 15:01:56 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		cd_prev(t_env *env)
{
	t_env	*tmp;
	char	*str;
	char	buf[512];

	tmp = env;
	str = NULL;
	ft_bzero(buf, 512);
	while (env)
	{
		if (ft_strcmp(env->name, "OLDPWD") == 0)
			str = ft_strsub(ft_strchr(env->line, '='), 1, ft_strlen(env->line));
		env = env->next;
	}
	env = tmp;
	if (str && getcwd(buf, 512))
	{
		change_directory(env, str);
		free(str);
	}
}

static void		cd_home(t_env *env)
{
	t_env	*tmp;
	char	*str;

	tmp = env;
	str = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
			str = ft_strdup(ft_strchr(env->line, '/'));
		env = env->next;
	}
	env = tmp;
	if (str)
	{
		change_directory(env, str);
		free(str);
	}
}

static char		*go_to_dir_from_root(t_env *env, char **cmd)
{
	t_env	*tmp;
	char	*str;

	tmp = env;
	str = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
			chdir(ft_strchr(env->line, '/'));
		env = env->next;
	}
	env = tmp;
	str = ft_strsub(cmd[1], 2, ft_strlen(cmd[1]));
	return (str);
}

static void		deal_with_cd_arg(t_env *env, char **cmd)
{
	struct stat	st;
	char		buf[512];

	ft_bzero(buf, 512);
	if (stat(cmd[1], &st) == -1 || !getcwd(buf, 512))
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
		return (1);
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
		cd_prev(env);
	else
		deal_with_cd_arg(env, cmd);
	return (0);
}
