/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:35:58 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/17 18:34:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

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

static int	delete_quotes(char *arg, char c, size_t *i)
{
	size_t	j;

	j = *i;
	ft_memmove(arg + *i, arg + *i + 1, ft_strlen(arg + *i + 1) + 1);
	if (check_for_sister(arg, c, i) == 1 && *i == ft_strlen(arg) - 1)
	{
		*i = 0;
		return (0);
	}
	else if (*i == ft_strlen(arg))
	{
		ft_memmove(arg + j + 1, arg + j, ft_strlen(arg + j + 1) + 1);
		arg[j] = c;
		*i = j;
		return (1);
	}
	return (2);
}

int			check_for_quotes(char *arg)
{
	static size_t	i;
	int				j;

	while (arg[i])
	{
		if (arg[i] == 39)
		{
			if ((j = delete_quotes(arg, 39, &i)) == 0)
				return (0);
			else if (j == 1)
				return (1);
		}
		if (arg[i] == 34)
		{
			if ((j = delete_quotes(arg, 34, &i)) == 0)
				return (0);
			else if (j == 1)
				return (1);
		}
		i++;
	}
	i = 0;
	return (0);
}
