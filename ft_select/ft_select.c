/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:41:45 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/22 15:37:36 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_deselect_all(t_term *termi)
{
	t_dblist	*tmp;

	termi->dblist->select = 0;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		tmp->select = 0;
		tmp = tmp->next;
	}
}

void	ft_select_all(t_term *termi)
{
	t_dblist	*tmp;
	int			i;

	i = 0;
	if (termi->dblist->select == 0)
	{
		termi->dblist->select = 1;
		i = 1;
	}
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->select == 0)
		{
			tmp->select = 1;
			i = 1;
		}
		tmp = tmp->next;
	}
	if (!i)
		ft_deselect_all(termi);
}
