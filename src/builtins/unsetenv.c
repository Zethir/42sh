/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 16:06:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int			do_unsetenv(t_env *env, char **arg, int flag)
{
	t_env	*tmp;

	arg++;
	tmp = env;
	if (!*arg)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (-1);
	}
	while (*arg)
	{
		while (env)
		{
			if (ft_strcmp(env->name, *arg) == 0 && env->flag == flag)
			{
				free(env->line);
				env->line = ft_strdup("");
			}
			env = env->next;
		}
		env = tmp;
		arg++;
	}
	return (0);
}
