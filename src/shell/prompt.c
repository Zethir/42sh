/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:48:35 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/22 14:25:03 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

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
	}
	else if (i == 0)
	{
		str = ft_strchr(buff, '/');
		color(PURPLE, str);
		color(RESET, "");
	}
}

static void	prompt_name(t_lst *node)
{
	t_lst	*tmp;

	tmp = node;
	while (node)
	{
		if (ft_strcmp(node->name, "USER") == 0)
		{
			color(CYAN, node->user);
			color(RESET, "");
		}
		node = node->next;
	}
	node = tmp;
	ft_putstr(" in ");
}

static int	cmp_pwd_home(t_lst *node, char *buff)
{
	t_lst	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (node)
	{
		if (ft_strcmp(node->name, "HOME") == 0)
		{
			if (ft_strcmp(node->home, buff) == 0)
				return (1);
			else if (ft_strncmp(node->home, buff, 20) == 0)
			{
				i = ft_strlen(node->home);
				return (i);
			}
		}
		node = node->next;
	}
	node = tmp;
	return (0);
}

static void	prompt_path(t_lst *node)
{
	char	buff[100];
	int		i;

	if (get_intel(node, "PWD") == 1)
	{
		getcwd(buff, 100);
		i = cmp_pwd_home(node, buff);
		deal_with_prompt_path(i, buff);
		return ;
	}
}

void		get_prompt(t_lst *node)
{
	color(BLUE, "# ");
	color(RESET, "");
	prompt_name(node);
	prompt_path(node);
	color(RED, " \n$> ");
	color(RESET, "");
}
