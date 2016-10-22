/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:29:03 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 12:05:20 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	export_new_variable(t_hub *info, int i)
{
	t_lst *tmp;

	tmp = info->lst;
	while (info->lst)
	{
		if (ft_strncmp(info->parse->argv[i], info->lst->name,
					ft_strlen(info->lst->name)) == 0 && info->lst->flag == 2)
		{
			info->lst->flag = 1;
			info->lst = tmp;
			return ;
		}
		info->lst = info->lst->next;
	}
	info->lst = tmp;
}

int		create_new_variable(t_hub *info)
{
	int		i;

	i = 0;
	while (info->parse->argv[i])
	{
		if (check_wrong_identifier(info, i) == 1)
			return (-1);
		else if (info->parse->argv[i][0] == '=')
		{
			print_identifier_error(info, i);
			return (-1);
		}
		if (check_local_variable(info, i, 2) == 0)
			add_to_list(info, info->lst, i, 2);
		i++;
	}
	return (0);
}
