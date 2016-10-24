/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:29:03 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 14:45:48 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	export_new_variable(t_env *env, char *arg)
{
	t_env *tmp;

	tmp = env;
	while (env)
	{
		if (ft_strncmp(arg, env->name, ft_strlen(env->name)) == 0 &&
				env->flag == 2)
		{
			env->flag = 1;
			env = tmp;
			return ;
		}
		env = env->next;
	}
	env = tmp;
}

int		create_new_variable(t_env *env, char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (check_wrong_identifier(arg[i]) == 1)
			return (-1);
		else if (arg[i][0] == '=')
		{
			print_identifier_error(arg[i]);
			return (-1);
		}
		if (check_local_variable(env, arg[i], 2) == 0)
			add_to_list(env, arg[i], 2);
		i++;
	}
	return (0);
}
