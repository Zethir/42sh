/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:55:13 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/21 19:25:07 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void		print_env(t_lst *node)
{
	t_lst *tmp;

	tmp = node;
	while (node)
	{
		if (!node->line)
			node = node->next;
		else if (node->flag == 0)
		{
			ft_putendl(node->line);
			node = node->next;
		}
	}
	node = tmp;
}

static int	cmp_line(t_hub *info, char **arg, char **env_cpy)
{
	char	*cmd;
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

static void	deal_with_arg(t_hub *info, char **arg, char **env_cpy)
{
	while (*arg)
	{
		if (cmp_line(info, arg, save[i]) == 0)
		{
			if (check_caract(*arg, '=') != 1)
			{
				cmd = join_env(arg);
				exec_env(info, cmd);
				return ;
			}
			else if (check_caract(*arg, '=') == 1)
				env_cpy = add_elem(env_cpy, *arg);
		}
		arg++;
	}
	ft_print_tab(env_cpy);
}

int			deal_with_env(t_hub *info, char **arg)
{
	char	**env_cpy;

	env_cpy = get_env(info->lst);
	arg++;
	if (*arg)
	{
		if (*arg[0] == '-')
			deal_with_opt(info, arg);
		else
			deal_with_arg(info, arg);
		free(env_cpy);
	}
	else
		print_env(info->lst);
	return (0);
}
