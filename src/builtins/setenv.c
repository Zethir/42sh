/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:39:25 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 15:59:29 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int	cmp_list_arg(t_env *env, char **arg)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, *arg) == 0 && env->flag == 0)
		{
			env->line = ft_strjoin(*arg, "=");
			if (arg[1])
				env->line = ft_strjoin(env->line, arg[1]);
			env = tmp;
			return (1);
		}
		env = env->next;
	}
	env = tmp;
	return (0);
}

static void	handle_arg_setenv(t_env *env, char **arg)
{
	t_env *new_elem;

	if ((arg[0][0] >= 'A' && arg[0][0] <= 'Z') ||
			(arg[0][0] >= 'a' && arg[0][0] <= 'z'))
	{
		if (cmp_list_arg(env, arg) == 0)
		{
			new_elem = (t_env *)malloc(sizeof(t_env));
			new_elem->next = NULL;
			new_elem->line = ft_strjoin(*arg, "=");
			new_elem->name = ft_strdup(*arg);
			new_elem->flag = 0;
			if (arg[1])
				new_elem->line = ft_strjoin(new_elem->line, arg[1]);
			push_node(new_elem, &env);
		}
	}
	else
		ft_putendl_fd("setenv: Variable name must begin with a letter.", 2);
}

int			do_setenv(t_env *env, char **arg)
{
	int		i;

	arg++;
	i = 1;
	while (arg[i])
		i++;
	if (i > 2)
		ft_putendl_fd("setenv: Too many arguments", 2);
	else if (!*arg)
		print_env(env);
	else if (print_alpha_error(arg) == 1)
		return (-1);
	else
		handle_arg_setenv(env, arg);
	return (-1);
}
