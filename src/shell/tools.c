/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:52:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/15 14:13:44 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int			get_index(t_env *node)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = node;
	while (node)
	{
		i++;
		node = node->next;
	}
	node = tmp;
	return (i);
}

static int	check_for_sister(char *arg, char c, size_t *i)
{
	while (arg[*i])
	{
		if (arg[*i] == c)
		{
			ft_memmove(arg + *i, arg + *i + 1, ft_strlen(arg + *i + 1) + 1);
			*i -= 1;
			return (1);
		}
		(*i)++;
	}
	return (0);
}

int			check_for_quotes(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 39)
		{
			ft_memmove(arg + i, arg + i + 1, ft_strlen(arg + i + 1) + 1);
			if (check_for_sister(arg, 39, &i) == 1 && i == ft_strlen(arg))
				return (0);
			else if (i == ft_strlen(arg))
				return (1);
		}
		if (arg[i] == 34)
		{
			ft_memmove(arg + i, arg + i + 1, ft_strlen(arg + i + 1) + 1);
			if (check_for_sister(arg, 34, &i) == 1 && i == ft_strlen(arg))
				return (0);
			else if (i == ft_strlen(arg))
				return (1);
		}
		i++;
	}
	return (0);
}

int			check_caract(char *str, char c)
{
	int		i;

	i = 0;
	if (str[i] == c)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		**add_elem(char **tabl, char *arg)
{
	char	**res;
	char	*tmp;
	char	*tmp2;

	tmp = join_tab(tabl);
	tmp2 = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strjoin(tmp2, arg);
	free(tmp2);
	res = ft_strsplit_ws(tmp);
	free(tmp);
	return (res);
}
