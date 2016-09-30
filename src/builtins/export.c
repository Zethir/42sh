/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 11:45:51 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 16:47:40 by qdiaz            ###   ########.fr       */
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
		if (ft_strncmp(lex->info->arg[i], node->name, ft_strlen(node->name)) == 0
				&& node->flag == 1)
		{	
			node->line = lex->info->arg[i];
			return (1);
		}
		node = node->next;
	}
	node = tmp;
	return (0);
}

static void	add_to_list(t_lex *info, t_lst *node, int j)
{
	t_lst	*new_elem;
	int		i;

	i = ft_strlen_char(lex->info->arg[j], '=');
	new_elem = (t_lst *)malloc(sizeof(t_lst));
	new_elem->next = NULL;
	new_elem->line = ft_strdup(lex->info->arg[j]);
	new_elem->name = (char *)malloc(sizeof(i) + 1);
	ft_strncpy(new_elem->name, lex->info->arg[j], i);
	new_elem->flag = 1;
	push_node(new_elem, &node);
}

void	do_export(t_lex *lex)
{
	int		i;

	i = 1;
	if (lex->info->arg[1])
	{
		while (lex->info->arg[i])
		{
			if (check_wrong_identifier(lex->info, i) == 1)
				return ;
			else if (lex->info->arg[i][0] == '=')
			{
				print_identifier_error(lex->info, i);
				return ;
			}
			if (check_local_variable(lex->info, lex->info->lst, i) == 0)
				add_to_list(lex->info, lex->info->lst, i);
			i++;
		}
	}
	else
		print_local(lex->info->lst);
}
