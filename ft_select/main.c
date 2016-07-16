/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:35:35 by qdiaz             #+#    #+#             */
/*   Updated: 2016/07/16 18:34:18 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_do_select(char **argv, t_term *termi)
{
	tputs(tgetstr("do", NULL), 1, ft_myputchar);
	tputs(tgetstr("sc", NULL), 1, ft_myputchar);
	arg_to_list(argv, termi);
	count_col(termi);
	ft_print(termi);
	ft_check_size(termi);
	ft_stock(termi, 0);
	while (1)
	{
		if (!ft_key(termi))
			return (0);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_term		termi;

	(void)argc;
	signal(SIGINT, SIG_IGN);
	termi.dblist = NULL;
	ft_signal();
	if (!ft_init_termios(&termi))
		return (-1);
	if (argc >= 2)
		ft_do_select(argv, &termi);
	if (!ft_end_termios(&termi))
		return (-1);
	return (0);
}
