/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:52:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/21 22:56:57 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	color(char *color, char *str)
{
	ft_putchar_fd('\033', 2);
	ft_putstr_fd(color, 2);
	ft_putstr_fd(str, 2);
}

int		get_index(t_lst *node)
{
	t_lst	*tmp;
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

int		ft_strccmp(const char *s1, const char *s2, char c)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (*tmp1 && *tmp1 == *tmp2 && *tmp1 != c)
	{
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}

int		check_for_parenth(char *arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] == '{' || arg[i] == '[' || arg[i] == '<' ||
				arg[i] == '(' || arg[i] == 39 || arg[i] == 34)
			j++;
		else if (arg[i] == '}' || arg[i] == ']' || arg[i] == '>' ||
					arg[i] == ')')
			j--;
		i++;
	}
	if (j == 0 || j % 2 == 0)
		return (0);
	else
		return (-1);
}
