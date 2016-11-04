/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:06:02 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/04 18:46:06 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

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

t_env	*delete_elem(t_env *node)
{
	t_env	*tmp;
	t_env	*tmp2;

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
