/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parser_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:50:42 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/30 16:02:09 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int     get_index(t_lst *node)
{
	t_lst   *tmp;
	int     i;

	i = 0;
	tmp = node;
	while (node)
	{
		i++;
		node = node->next;
	}
	node = tmp;
	return (i);
}

int		list_browser(t_lex *lex)
{
	t_lex 	*tmp;
	int		i;
	
	tmp = lex;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
