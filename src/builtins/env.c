/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:55:13 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 15:09:01 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		print_env(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (env)
	{
		if (!env->line)
			env = env->next;
		else if (env->flag == 0)
		{
			ft_putendl(env->line);
			env = env->next;
		}
		else
			env = env->next;
	}
	env = tmp;
}

static int	cmp_line(char **arg, char **env_cpy)
{
	int		i;

	i = 0;
	while (env_cpy[i])
	{
		if (ft_strccmp(env_cpy[i], *arg, '=') == 0)
		{
			free(env_cpy[i]);
			env_cpy[i] = ft_strdup(*arg);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	deal_with_arg(t_shell *sh, char **arg, char **env_cpy)
{
	char	**res;
	char	*cmd;

	res = NULL;
	while (*arg)
	{
		if (cmp_line(arg, env_cpy) == 0)
		{
			if (check_caract(*arg, '=') != 1)
			{
				cmd = join_tab(arg);
				exec_env(sh, cmd, env_cpy);
				return ;
			}
			else if (check_caract(*arg, '=') == 1)
			{
				res = add_elem(env_cpy, *arg);
				ft_print_tab(res);
				ft_free_tab(res);
				return ;
			}
		}
		arg++;
	}
	ft_print_tab(env_cpy);
}

int			deal_with_env(t_shell *sh, char **arg)
{
	char	**env_cpy;

	env_cpy = get_env(sh->env);
	arg++;
	if (*arg)
	{
		if (*arg[0] == '-')
			deal_with_opt(sh, arg, env_cpy);
		else
			deal_with_arg(sh, arg, env_cpy);
	}
	else
		print_env(sh->env);
	ft_free_tab(env_cpy);
	return (0);
}
