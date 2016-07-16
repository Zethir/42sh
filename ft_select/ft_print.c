/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:57:04 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/19 16:21:42 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_under_line(char *str)
{
	tputs(tgetstr("us", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[32m", 0);
	ft_putendl_fd(str, 0);
	ft_putstr_fd("\033[00m", 0);
	tputs(tgetstr("ue", NULL), 1, ft_myputchar);
}

static void		ft_print_select(char *str)
{
	tputs(tgetstr("so", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[32m", 0);
	ft_putendl_fd(str, 0);
	ft_putstr_fd("\033[00m", 0);
	tputs(tgetstr("se", NULL), 1, ft_myputchar);
}

static void		ft_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, ft_myputchar);
	tputs(tgetstr("so", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[1;36m", 0);
	ft_putendl_fd(str, 0);
	ft_putstr_fd("\033[00m", 0);
	tputs(tgetstr("se", NULL), 1, ft_myputchar);
	tputs(tgetstr("ue", NULL), 1, ft_myputchar);
}

static void		ft_behaviour(t_dblist *list)
{
	if (list->line == 1 && list->select == 1)
		ft_underline(list->value);
	else if (list->line == 1)
		ft_under_line(list->value);
	else if (list->select == 1)
		ft_print_select(list->value);
	else
		ft_putendl_fd(list->value, 2);
}

void			ft_print(t_term *termi)
{
	int			i;
	int			max;
	t_dblist	*tmp;

	i = 1;
	max = -1;
	tmp = NULL;
	ft_behaviour(termi->dblist);
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		max = ft_op_display(termi, i, max);
		i++;
		ft_behaviour(tmp);
		tmp = tmp->next;
	}
}
