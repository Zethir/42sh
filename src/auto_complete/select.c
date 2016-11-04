/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:41:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/04 15:17:14 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

char		*do_select(char **argv, int id)
{
	t_struct	*info;
	char		*str;
	char		tmp[30];

	info = init_select_struct(argv);
	ttyname_r(0, tmp, 13);
	info->fd = open(tmp, O_RDWR);
	if (info->fd == -1)
		return (NULL);
	stock_select_struct(info, 0);
	tputs(tgetstr("cr", NULL), 0, ft_putchar_int);
	tputs(tgetstr("do", NULL), 0, ft_putchar_int);
	tputs(tgetstr("sc", NULL), 0, ft_putchar_int);
	win_select_size(id);
	while (1)
	{
		str = deal_with_term(info);
		if (str || info->on == 1)
			break ;
	}
	if (close(info->fd) < 0)
		ft_putendl_fd("Can't close fd", 2);
	free_lst(info);
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
	tputs(tgetstr("up", NULL), 1, ft_putchar_int);
	if (str && str[0])
		return (str);
	return (NULL);
}
