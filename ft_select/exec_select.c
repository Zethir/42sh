/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:49:21 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/26 20:47:12 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*do_select(char **argv, int id)
{
	t_sel_struct	*info;
	char		*str;
	size_t		tmp;

	info = init_sel_struct(argv);
	if (init_sel_term(info) == -1)
		return (NULL);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	stock_sel_struct(info, 0);
	win_size(id);
	tmp = info->size_last;
	while (tmp-- > 0)
		tputs(tgetstr("up", NULL), 1, ft_putchar_int);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	while (1)
	{
		str = deal_with_term(info);
		if (str)
			break ;
	}
	if (reset_sel_term(info) == -1)
		return (NULL);
	return (str);
}

int		exec_select(int argc, char **argv)
{
	char		*str;
	int			id;

	id = 0;
	signal(SIGINT, SIG_IGN);
	ft_signal_sel(id);
	if (argc >= 2)
		str = do_select(argv, id);
	else
	{
		ft_putendl_fd("Too few argument to function call", 2);
		return (1);
	}
	if (str)
	{
		ft_putendl(str);
		free(str);
	}
	else
		ft_putendl_fd("String empty, problem with env", 2);
	return (0);
}
