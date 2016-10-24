/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:41:53 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 14:14:16 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		go_to_root(t_env *env)
{
	t_env		*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
		{
			env->home = ft_strchr(env->home, '/');
			chdir(env->home);
			return ;
		}
		env = env->next;
	}
	env = tmp;
}

static char		*deal_with_root(t_env *env, char *arg)
{
	char		*tmp;

	if (!arg[1])
		go_to_root(env);
	else if (arg[1] == '/')
	{
		go_to_root(env);
		if (arg[2])
			tmp = ft_strsub(arg, 2, ft_strlen(arg));
		else
			tmp = ft_strsub(arg, 1, ft_strlen(arg));
		return (tmp);
	}
	else
	{
		ft_putstr_fd("Unknown user: ", 2);
		ft_putstr_fd(&arg[1], 2);
		ft_putendl_fd(".", 2);
	}
	return (NULL);
}

static void		deal_with_cd_arg(char *arg)
{
	DIR			*dir;
	struct stat	st;

	dir = opendir(arg);
	if (stat(arg, &st) == -1)
	{
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": No such file or directory.", 2);
	}
	else if (!(S_ISDIR(st.st_mode)))
	{
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": Not a directory", 2);
	}
	else if (access(arg, X_OK) == -1)
	{
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": Permission denied: ", 2);
	}
	else
		chdir(arg);
	if (dir)
		closedir(dir);
}

int				do_cd(t_env *env, char **arg)
{
	int			i;

	arg++;
	i = 0;
	while (arg[i])
		i++;
	if (i > 1)
	{
		ft_putendl_fd("cd: Too many arguments.", 2);
		return (-1);
	}
	else if (!*arg)
		go_to_root(env);
	else if (*arg[0] == '~')
	{
		*arg = deal_with_root(env, *arg);
		if (!*arg)
			return (-1);
	}
	if (*arg)
		deal_with_cd_arg(*arg);
	return (0);
}
