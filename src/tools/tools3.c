/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 00:06:48 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 16:43:28 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	win_size(int id)
{
	t_shell			*sh;
	t_prompt		*prompt;
	char			*str;
	struct winsize	win;

	(void)id;
	sh = NULL;
	str = ft_strdup("");
	sh = stock_struct(sh, 1);
	prompt = NULL;
	prompt = stock_prompt(prompt, 1);
	ioctl(0, TIOCGWINSZ, &win);
	prompt->win_size = win.ws_col;
	prompt_print(prompt, str);
	free(str);
}

char	*get_home(t_env *node)
{
	char	*str;

	str = ft_strdup("");
	while (node)
	{
		if (ft_strcmp(node->name, "HOME") == 0)
		{
			str = ft_strjoin(ft_strchr(node->line, '/'), "/history");
			break ;
		}
		node = node->next;
	}
	return (str);
}

char	*join_env(char **arg)
{
	char	*res;
	int		i;

	res = arg[0];
	i = 0;
	while (arg[i])
	{
		if (arg[i + 1])
		{
			res = ft_strjoin(res, " ");
			res = ft_strjoin(res, arg[i + 1]);
		}
		i++;
	}
	return (res);
}
