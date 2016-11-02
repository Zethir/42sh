/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:55:13 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 18:11:35 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		print_env(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (env)
	{
		if (ft_strlen(env->line) < 1)
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
			env_cpy[i] = ft_strdup(*arg);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	deal_with_arg(t_shell *sh, char **arg, char **env_cpy)
{
	char	*cmd;

	while (*arg)
	{
		if (cmp_line(arg, env_cpy) == 0)
		{
			if (check_caract(*arg, '=') != 1)
			{
				cmd = join_env(arg);
				exec_env(sh, cmd, env_cpy);
				return ;
			}
			else if (check_caract(*arg, '=') == 1)
				env_cpy = add_elem(env_cpy, *arg);
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
