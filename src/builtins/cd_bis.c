/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:14:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 16:51:08 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		change_varcontent(t_env *env, char *name_ref, char *data)
{
	t_env	*tmp;
	char	*str;

	tmp = env;
	while (env)
	{
		if (!(ft_strcmp(env->name, name_ref)))
		{
			if (env->line)
				ft_strdel(&(env->line));
			str = ft_strjoin(env->name, "=");
			env->line = ft_strjoin(str, data);
			free(str);
		}
		env = env->next;
	}
	env = tmp;
}
	
void		change_directory(t_env *env, char *cmd)
{
	char		buf[512];

	ft_bzero(buf, 512);
	getcwd(buf, 512);
	if (buf[0] != 0)
	{
		change_varcontent(env, "OLDPWD", buf);
		chdir(cmd);
		change_varcontent(env, "PWD", buf);
	}
	else
		ft_putendl_fd("Directory does not exist", 2);
}
