/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 11:45:51 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/10 13:27:32 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh21.h"

static void	print_local(t_lst *node)
{
	t_lst *tmp;

	tmp = node;
	while (node)
	{
		if (!node->line)
			node = node->next;
		else if (node->flag == 1)
		{
			ft_putstr("export ");
			ft_putendl(node->line);
		}
		node = node->next;
	}
	node = tmp;
}

static int	check_token(t_struct *info)
{
	if (check_wrong_identifier(info) == 1)
		 return (1);
	else if (info->arg[1][0] == '=')
		print_identifier_error(info);
	//add_local_variable();	
	return (0);
}

void	do_export(t_struct *info)
{
	if (info->arg[1])
		check_token(info);
	else
		print_local(info->lst);
}
