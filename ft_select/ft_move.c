/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:23:23 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/19 14:47:05 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_left(t_term *termi)
{
	int			i;
	int			nb_col;
	int			nb_files_in_col;
	t_dblist	*tmp;

	tmp = termi->dblist;
	nb_col = termi->nb_col / (max_size(termi) + 2);
	nb_files_in_col = (list_size(termi) + 1) / nb_col;
	i = 0;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	while (nb_files_in_col-- + 1)
	{
		if (tmp == termi->dblist)
			break ;
		tmp = tmp->prev;
	}
	tmp->line = 1;
}

void		ft_right(t_term *termi)
{
	int			i;
	int			nb_col;
	int			nb_files_in_col;
	t_dblist	*tmp;

	tmp = termi->dblist;
	nb_col = termi->nb_col / (max_size(termi) + 2);
	nb_files_in_col = (list_size(termi) + 1) / nb_col;
	i = 0;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	while (nb_files_in_col-- + 1)
	{
		if (tmp->next == termi->dblist)
			break ;
		tmp = tmp->next;
	}
	tmp->line = 1;
}
