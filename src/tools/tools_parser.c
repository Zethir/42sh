/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parser_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:50:42 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/30 18:44:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		list_browser(t_lex *lex)
{
	t_cmd 	*tmp;
	int		i;
	
	i = 0;
	tmp = lex->cmd;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
