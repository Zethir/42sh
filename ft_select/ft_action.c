/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:26:13 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/19 16:33:49 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_goto_begin(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	termi->dblist->line = 1;
}

void			ft_goto_end(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	termi->dblist->prev->line = 1;
}

void			ft_space_key(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	if (tmp->select == 0)
		tmp->select = 1;
	else
		tmp->select = 0;
	tmp->line = 0;
	tmp->next->line = 1;
}

int				ft_delete(t_term *termi)
{
	t_dblist	*tmp;

	if (termi->dblist == termi->dblist->next)
	{
		free(termi->dblist);
		return (0);
	}
	tmp = termi->dblist;
	if (termi->dblist->line == 1)
		termi->dblist = tmp->next;
	else
	{
		while (tmp->line != 1)
			tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next->line = 1;
	free(tmp->value);
	free(tmp);
	count_col(termi);
	termi->count[0] -= 1;
	return (1);
}

void			ft_tab_key(t_term *termi)
{
	ft_deselect_all(termi);
	ft_space_key(termi);
}
