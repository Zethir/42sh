/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:06:02 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/21 20:00:17 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		check_caract(char *str, char c)
{
	int		i;

	i = 0;
	if (str[i] == c)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_lst	*delete_elem(t_lst *node)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = node;
	tmp2 = node;
	if (node == NULL)
		return (NULL);
	if (node->next == NULL)
	{
		free(node);
		return (NULL);
	}
	while (tmp->next != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	return (node);
}

char	**add_elem(char **tabl, char *arg)
{
	char	**res;
	int		size_tab;

	size_tab = ft_tablen(tabl);
	if (!(res = (char **)malloc(sizeof(char *) * (size_tab + 1))))
		return (NULL);
	res = tabl;
	res[size_tab] = arg;
	res[size_tab + 1] = NULL;
	return (res);
}

char	**malloc_tab(char **arg)
{
	int		i;
	char	**save;

	i = 0;
	while (arg[i])
		i++;
	save = (char **)malloc(sizeof(char *) * i + 1);
	if (!save)
		return (NULL);
	save[i + 1] = NULL;
	return (save);
}
