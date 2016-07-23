/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:55:39 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/23 18:18:36 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	do_designator(t_struct *info, char **cmd)
{
	if (cmd[0][1] == '-')
	{
		if (check_number_bis(cmd) == 0)
			deal_with_dash(info, cmd);
	}
	if (cmd[0][1] >= 0 && cmd[0][1] <= 9)
	{
		if (check_number(cmd) == 0)
			deal_with_number(info, cmd);
	}
	else
	{
		if (check_alpha(cmd) == 0)
			deal_with_string(info, cmd);
	}
}	
