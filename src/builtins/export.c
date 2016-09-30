/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 11:45:51 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 18:07:04 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

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

static int	check_local_variable(t_lex *lex, t_lst *node, int i)
{
	t_lst	*tmp;

	tmp = node;
	while (node)
	{
		if (ft_strncmp(lex->cmd->argv[i], node->name, ft_strlen(node->name)) == 0
				&& node->flag == 1)
		{	
			node->line = lex->cmd->argv[i];
			return (1);
		}
		node = node->next;
	}
	node = tmp;
	return (0);
}

static void	add_to_list(t_hub *info, t_lst *node, int j)
{
	t_lex	*lex;
	t_lst	*new_elem;
	int		i;

	lex = info->lex;
	i = ft_strlen_char(lex->cmd->argv[j], '=');
	new_elem = (t_lst *)malloc(sizeof(t_lst));
	new_elem->next = NULL;
	new_elem->line = ft_strdup(lex->cmd->argv[j]);
	new_elem->name = (char *)malloc(sizeof(i) + 1);
	ft_strncpy(new_elem->name, lex->cmd->argv[j], i);
	new_elem->flag = 1;
	push_node(new_elem, &node);
}

void	do_export(t_hub *info)
{
	t_lex *lex;
	int		i;

	i = 1;
	lex  = info->lex;
	if (lex->cmd->argv[1])
	{
		while (lex->cmd->argv[i])
		{
			if (check_wrong_identifier(lex, i) == 1)
				return ;
			else if (lex->cmd->argv[i][0] == '=')
			{
				print_identifier_error(lex, i);
				return ;
			}
			if (check_local_variable(lex, lex->info->lst, i) == 0)
				add_to_list(lex, info->lst, i);
			i++;
		}
	}
	else
		print_local(info->lst);
}
