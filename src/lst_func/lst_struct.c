/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:17:17 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/18 18:18:17 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

t_hub	*stock_struct(t_hub *info, int i)
{
	static t_hub *tmp = NULL;

	if (i == 0)
		tmp = info;
	return (tmp);
}

t_hub	*init_struct(char **env)
{
	t_hub	*info;

	if (!(info = (t_hub *)malloc(sizeof(t_hub))))
		return (NULL);
	info->lst = init_lst(env);
	if (!(info->node = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	info->node = create_node();
	deal_with_file(info);
	if (!(info->prompt = (t_prompt *)malloc(sizeof(t_prompt))))
		return (NULL);
	info->prompt->copy_mode = 0;	
	info->prompt->cursor_start = 0;	
	info->prompt->cursor_end = 0;
	info->prompt->copy_str = ft_strdup("");
	if (init_term(info) == -1)
		return (NULL);
	return (info);
}

void	init_stdio(t_hub *info)
{
	if (!(info->stdio = (int *)malloc(sizeof(int) * 3)))
		return ;
	info->stdio[0] = 0;
	info->stdio[1] = 1;
	info->stdio[2] = 2;
	info->closefd = -1;
}
