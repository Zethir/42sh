/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:00:25 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/01 15:33:31 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		push_cmd(t_cmd *node, t_cmd **head)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;

	tmp2 = *head;
	if (tmp2->argv == NULL)
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

void			add_cmd(t_lex *lex, char *new_cmd, int index)
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
	new_elem->argv = ft_strsplit_ws(new_cmd);
	new_elem->index = index;
	push_cmd(new_elem, &lex->cmd);
}

t_cmd			*init_cmd_struct(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->next = NULL;
	cmd->argv = NULL;
	cmd->index = 0;
	return (cmd);
}
