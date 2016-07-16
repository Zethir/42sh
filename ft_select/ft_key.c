/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:20:33 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/19 17:38:24 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			count_col(t_term *termi)
{
	t_dblist	*tmp;

	termi->count[0] = termi->dblist->len;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->len > termi->count[0])
			termi->count[0] = tmp->len;
		tmp = tmp->next;
	}
}

void			ft_stock_tab(t_term *termi)
{
	t_dblist	*tmp;
	int			i;

	i = 0;
	if (termi->dblist->select == 1)
	{
		termi->ret_tab[i] = ft_strdup(termi->dblist->value);
		i++;
	}
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->select == 1)
		{
			termi->ret_tab[i] = ft_strdup(tmp->value);
			i++;
		}
		tmp = tmp->next;
	}
	termi->ret_tab[i] = 0;
}

void			ft_return_key(t_term *termi)
{
	t_dblist	*tmp;
	int			count;

	count = 0;
	termi->enter = 1;
	if (termi->dblist->select == 1)
		count++;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->select == 1)
			count++;
		tmp = tmp->next;
	}
	termi->ret_tab = (char **)malloc(sizeof(char *) * (count + 1));
	ft_stock_tab(termi);
}

static void		ft_manage_key(t_term *termi, char *buffer[5])
{
	if (BUFFER == DOWN_KEY)
		ft_down(termi);
	if (BUFFER == UP_KEY)
		ft_up(termi);
	if (BUFFER == LEFT_KEY)
		ft_left(termi);
	if (BUFFER == RIGHT_KEY)
		ft_right(termi);
	if (BUFFER == SPACE_KEY)
		ft_space_key(termi);
	if (BUFFER == HOME_KEY)
		ft_goto_begin(termi);
	if (BUFFER == END_KEY)
		ft_goto_end(termi);
	if (BUFFER == CRTL_A_KEY)
		ft_select_all(termi);
	if (BUFFER == TAB_KEY)
		ft_tab_key(termi);
}

int				ft_key(t_term *termi)
{
	char	*buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESC_KEY)
		return (0);
	if (ft_check_size(termi))
	{
		ft_manage_key(termi, buffer);
		if (BUFFER == DEL_KEY || BUFFER == SUP_KEY)
		{
			if (!ft_delete(termi))
				return (0);
		}
		if (BUFFER == RET_KEY)
		{
			ft_return_key(termi);
			return (0);
		}
		screen_clear();
		ft_print(termi);
	}
	return (1);
}
