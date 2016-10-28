/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:14:22 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 17:30:17 by cboussau         ###   ########.fr       */
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
