/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:45:03 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/21 20:19:08 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int	check_arg(char **env_cpy, char *arg)
{
	int		i;

	i = 0;
	while (env_cpy[i])
	{
		if (ft_strncmp(env_cpy[i], arg, ft_strclen(env_cpy[i], '=')) == 0)
		{
			env_cpy[i] = ft_strdup("");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_i_opt(t_hub *info, char **arg, char **env_cpy)
{
	char	*cmd;

	if (arg[0][0] == '-' && arg[0][1] == 'i' && !arg[0][2] && arg[1])
	{
		arg++;
		cmd = join_env(arg);
		env_cpy = NULL;
		exec_env(info, cmd, env_cpy);
		return (0);
	}
	else
		return (1);
}

static int	check_u_opt(t_hub *info, char **arg, char **env_cpy)
{
	char	*cmd;

	if (arg[0][0] == '-' && arg[0][1] == 'u' && !arg[0][2] && arg[1])
	{
		arg++;
		if (check_arg(env_cpy, *arg) == 0)
			print_error_opt(*arg);
		arg++;
		if (*arg)
		{
			cmd = join_env(arg);
			exec_env(info, cmd, env_cpy);
		}
		else
			ft_print_tab(env_cpy);
		return (0);
	}
	else
		return (1);
}

void		deal_with_opt(t_hub *info, char **arg, char **env_cpy)
{
	if (check_u_opt(info, arg, env_cpy) ==  1 &&
			check_i_opt(info, arg, env_cpy) == 1)
	{
		if (!arg[1] && !arg[0][2] && (arg[0][1] == 'u' || arg[0][1] == 'i'))
			print_error_arg();
		else
			print_main_error(&*arg[0]);
	}
}
