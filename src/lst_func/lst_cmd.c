/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:00:25 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/28 14:59:50 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static void		push_cmd(t_cmd *node, t_cmd **head)
{
	t_cmd	*tmp;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void			add_cmd(t_cmd *cmd, char *new_cmd, int index)
{
	t_cmd	*new_elem;
	int		i;

	i = 0;
	if (!(new_elem = (t_cmd *)malloc(sizeof(t_cmd))))
		return ;
	while (new_cmd[i])
		i++;
	if (ft_isdigit(new_cmd[i - 1]))
		new_cmd = ft_strsub(new_cmd, 0, i - 1);
	new_elem->next = NULL;
	new_elem->str = ft_strdup(new_cmd);
	new_elem->index = index;
	push_cmd(new_elem, &cmd);
}
