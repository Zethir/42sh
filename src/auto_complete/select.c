/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:41:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/26 19:42:55 by qdiaz            ###   ########.fr       */
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
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	tputs(tgetstr("do", NULL), 1, ft_putchar_int);
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
	tputs(tgetstr("up", NULL), 1, ft_putchar_int);
	if (str)
		return (str);
	return (NULL);
}
