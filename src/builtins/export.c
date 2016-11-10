/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 11:45:51 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/10 17:52:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		print_local(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (env)
	{
		if (!env->line)
			env = env->next;
		else if (env->flag == 1)
		{
			ft_putstr("export ");
			ft_putendl(env->line);
			env = env->next;
		}
		else
			env = env->next;
	}
	env = tmp;
}

int				check_local_variable(t_env *env, char *arg, int flag)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strncmp(arg, env->name, ft_strlen(env->name)) == 0 &&
				env->flag == flag)
		{
			if (ft_strchr(arg, '=') != NULL)
				env->line = arg;
			env = tmp;
			return (1);
		}
		env = env->next;
	}
	env = tmp;
	return (0);
}

void			add_to_list(t_env *env, char *arg, int flag)
{
	t_env	*new_elem;
	int		i;

	i = ft_strlen_char(arg, '=');
	new_elem = (t_env *)malloc(sizeof(t_env));
	new_elem->next = NULL;
	new_elem->line = ft_strdup(arg);
	new_elem->name = (char *)malloc(sizeof(i) + 1);
	ft_strncpy(new_elem->name, arg, i);
	new_elem->flag = flag;
	push_node(new_elem, &env);
}

static int		export_arg(t_env *env, char *arg)
{
	if (check_wrong_identifier(arg) == 1)
		return (-1);
	else if (arg[0] == '=')
	{
		print_identifier_error(arg);
		return (-1);
	}
	if (check_local_variable(env, arg, 1) == 0)
	{
		if (check_local_variable(env, arg, 2) == 0)
			add_to_list(env, arg, 1);
		else
			export_new_variable(env, arg);
	}
	return (0);
}

int				do_export(t_env *env, char **arg)
{
	int		i;

	i = 1;
	if (arg[1])
	{
		while (arg[i])
		{
			if (export_arg(env, arg[i]) == -1)
				return (1);
			i++;
		}
	}
	else
		print_local(env);
	return (0);
}
