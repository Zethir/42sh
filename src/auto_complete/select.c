/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:49:21 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/26 15:37:43 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

char	*do_select(char **argv, int id)
{
	t_struct	*info;
	char		*str;

	info = init_select_struct(argv);
	info->fd = open(ttyname(0), O_RDWR);
	if (info->fd == -1)
		return (NULL);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_int);
	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	stock_select_struct(info, 0);
	win_select_size(id);
	while (1)
	{
		str = deal_with_term(info);
		if (str)
			break ;
	}
	if (close(info->fd) < 0)
		ft_putendl_fd("Can't close fd", 2);
	return (str);
}

char		*main_select(int argc, char **argv)
{
	char		*str;
	int			id;

	id = 0;
	if (argc >= 2)
		str = do_select(argv, id);
	else
	{
		ft_putendl_fd("Too few argument to function call", 2);
		return (NULL);
	}
	if (str)
		return (str);
	return (NULL);
}
