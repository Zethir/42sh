/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 10:16:04 by tvallee           #+#    #+#             */
/*   Updated: 2015/11/27 18:21:42 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

static char			*not_an_option(char badc)
{
	static char		c = 0;

	if (badc)
		c = badc;
	return (c ? &c : NULL);
}

static uintmax_t	get_opt(char *opt, char **validopts, int soloopt)
{
	size_t	i;

	i = 0;
	if (soloopt && *opt == '-')
	{
		while (validopts[i])
			if (!ft_strcmp(validopts[i++], opt + 1))
				return (1 << (i - 1));
		return (0);
	}
	else
	{
		if (*opt == 0)
			return (0);
		while (validopts[i])
		{
			if (validopts[i][0] == *opt && !validopts[i][1])
				break ;
			i++;
		}
		if (!validopts[i])
			return ((uintmax_t)(not_an_option(*opt)) * 0);
		return (1 << i | get_opt(opt + 1, validopts, 0));
	}
}

static void			remove_line(char **av)
{
	while (av[1])
	{
		av[0] = av[1];
		av++;
	}
	av[0] = NULL;
}

char				*ft_getopt_emsg(char *emsg)
{
	static char		*err = NULL;

	if (emsg)
		err = emsg;
	else
		return (err);
	return (err);
}

int					ft_getopt(int *ac, char **av, char **validopts,
																uintmax_t *opts)
{
	uintmax_t	ret;
	char		buf[21];

	*opts = 0;
	while (*av != NULL)
	{
		if (av[0][0] == '-' && av[0][1] && (*ac)--)
		{
			ret = get_opt(*av + 1, validopts, 1);
			if (!ret || not_an_option(0))
			{
				ft_strcpy(buf, "illegal option: -- ");
				ft_getopt_emsg((not_an_option(0)) ? ft_strdup(ft_strncat(buf,
								(not_an_option(0)), 1)) : ft_getopt_emsg(
								ft_strjoin(buf, *av + 2, 0)));
				return (-1);
			}
			remove_line(av);
			*opts |= ret;
		}
		else
			av++;
	}
	return (0);
}
