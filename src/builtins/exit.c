/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:11:24 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 21:38:14 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	deal_with_int(t_shell *sh, t_job *job, t_parse *parse)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (parse->argv[j][i])
	{
		if (parse->argv[j][i] < '0' || parse->argv[j][i] > '9')
		{
			ft_putendl_fd("exit: Badly formed number.", 2);
			return (-1);
		}
		i++;
	}
	i = ft_atoi(parse->argv[1]);
	free_job(job);
	free_parse(&parse);
	reset_term(sh);
	exit(i);
}

int			do_exit(t_shell *sh, t_job *job, t_parse *parse)
{
	int		i;

	i = 1;
	if (!parse->argv[i])
	{
		free_job(job);
		free_parse(&parse);
		reset_term(sh);
		exit(0);
	}
	while (parse->argv[i])
		i++;
	if (i > 2)
	{
		ft_putendl_fd("exit: Expression Syntax.", 2);
		return (-1);
	}
	else if (deal_with_int(sh, job, parse) == -1)
		return (-1);
	return (-1);
}
