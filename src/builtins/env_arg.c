/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 18:45:03 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/13 15:58:12 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int	check_arg(char **env_cpy, char *arg)
{
	int		i;

	i = 0;
	while (env_cpy[i])
	{
		if (ft_strncmp(env_cpy[i], arg, ft_strlen(arg)) == 0)
		{
			free(env_cpy[i]);
			env_cpy[i] = ft_strdup("");
			ft_strclr(env_cpy[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_i_opt(t_shell *sh, char **arg, char **env_cpy)
{
	char	*cmd;

	if (arg[0][0] == '-' && arg[0][1] == 'i' && !arg[0][2] && arg[1])
	{
		arg++;
		cmd = join_tab(arg);
		env_cpy = NULL;
		exec_env(sh, cmd, env_cpy);
		free(cmd);
		return (0);
	}
	else
		return (1);
}

static int	check_u_opt(t_shell *sh, char **arg, char **env_cpy)
{
	char	*cmd;

	if (arg[0][0] == '-' && arg[0][1] == 'u' && !arg[0][2] && arg[1])
	{
		arg++;
		if (check_arg(env_cpy, *arg) == 0)
			return (print_error_opt(*arg));
		arg++;
		if (*arg)
		{
			cmd = join_tab(arg);
			exec_env(sh, cmd, env_cpy);
			free(cmd);
			return (sh->return_val);
		}
		else
			ft_print_tab(env_cpy);
		return (0);
	}
	else
		return (1);
}

int			deal_with_opt(t_shell *sh, char **arg, char **env_cpy)
{
	if (check_u_opt(sh, arg, env_cpy) == 1 &&
			check_i_opt(sh, arg, env_cpy) == 1)
	{
		if (!arg[1] && !arg[0][2] && (arg[0][1] == 'u' || arg[0][1] == 'i'))
			return (print_error_arg());
		else
			return (print_main_error(&*arg[0]));
	}
	return (0);
}
