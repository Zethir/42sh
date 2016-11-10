/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/10 17:32:00 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void	del(t_env *tmp)
{
	if (tmp->line)
		free(tmp->line);
	if (tmp->name)
		free(tmp->name);
	free(tmp);
	tmp = NULL;
}

static void	delete_elem_from_count(t_env **env, int count)
{
	t_env	*prev;
	t_env	*tmp;
	int		i;

	prev = NULL;
	tmp = *env;
	i = 0;
	while (i != count && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	if (i == count)
	{
		if (prev)
			prev->next = tmp->next;
		else
			*env = tmp->next;
		del(tmp);
	}
}

static void	browse_env(t_env *env, char *arg, int flag)
{
	t_env	*tmp;
	int		count;

	count = 0;
	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, arg) == 0 && env->flag == flag)
			delete_elem_from_count(&tmp, count);
		env = env->next;
		count++;
	}

}

int			do_unsetenv(t_env *env, char **arg, int flag)
{
	t_env	*tmp;

	arg++;
	tmp = env;
	if (!*arg)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (1);
	}
	while (*arg)
	{
		browse_env(env, *arg, flag);
		env = tmp;
		arg++;
	}
	return (0);
}
