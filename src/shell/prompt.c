/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:48:35 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 16:38:09 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		color(char *color, char *str)
{
	ft_putchar_fd('\033', 2);
	ft_putstr_fd(color, 2);
	ft_putstr_fd(str, 2);
}

static void	deal_with_prompt_path(int i, char *buff)
{
	char	*str;

	if (i >= 1)
	{
		color(PURPLE, "");
		ft_putchar('~');
		color(RESET, "");
	}
	if (i > 1)
	{
		str = ft_strdup(&buff[i]);
		color(PURPLE, str);
		color(RESET, "");
		free(str);
	}
	else if (i == 0)
	{
		str = ft_strdup(ft_strchr(buff, '/'));
		color(PURPLE, str);
		color(RESET, "");
		free(str);
	}
	ft_putchar('\n');
}

static void	prompt_name(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, "USER") == 0)
		{
			color(CYAN, env->user);
			color(RESET, "");
		}
		env = env->next;
	}
	env = tmp;
	ft_putstr(" in ");
}

static int	cmp_pwd_home(t_env *env, char *buff)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
		{
			if (ft_strcmp(env->home, buff) == 0)
				return (1);
			else if (ft_strncmp(env->home, buff, ft_strlen(env->home)) == 0)
			{
				i = ft_strlen(env->home);
				return (i);
			}
		}
		env = env->next;
	}
	env = tmp;
	return (0);
}

void		get_prompt(t_env *env)
{
	char	buff[100];
	int		i;

	color(BLUE, "# ");
	color(RESET, "");
	prompt_name(env);
	ft_bzero(buff, 100);
	if (get_intel(env, "PWD") == 1)
	{
		getcwd(buff, 100);
		if (buff[0] != 0)
		{
			i = cmp_pwd_home(env, buff);
			deal_with_prompt_path(i, buff);
		}
		else
			ft_putendl_fd("\033[31mDirectory does not exist\033[39m", 2);
	}
}
