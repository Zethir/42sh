/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 11:45:51 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/10 18:40:12 by qdiaz            ###   ########.fr       */
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

static int	check_local_variable(t_hub *info, int i)
{
	t_lst	*tmp;

	tmp = info->lst;
	while (info->lst)
	{
		if (ft_strncmp(info->parse->argv[i], info->lst->name,
					ft_strlen(info->lst->name)) == 0 && info->lst->flag == 1)
		{	
			info->lst->line = info->parse->argv[i];
			return (1);
		}
		info->lst = info->lst->next;
	}
	info->lst = tmp;
	return (0);
}

static void	add_to_list(t_hub *info, t_lst *node, int j)
{
	t_lex	*lex;
	t_lst	*new_elem;
	int		i;

	lex = info->lex;
	i = ft_strlen_char(info->parse->argv[j], '=');
	new_elem = (t_lst *)malloc(sizeof(t_lst));
	new_elem->next = NULL;
	new_elem->line = ft_strdup(info->parse->argv[j]);
	new_elem->name = (char *)malloc(sizeof(i) + 1);
	ft_strncpy(new_elem->name, info->parse->argv[j], i);
	new_elem->flag = 1;
	push_node(new_elem, &node);
}

int		do_export(t_hub *info)
{
	t_lex *lex;
	int		i;

	i = 1;
	lex  = info->lex;
	if (info->parse->argv[1])
	{
		while (info->parse->argv[i])
		{
			if (check_wrong_identifier(info, i) == 1)
				return (-1);
			else if (info->parse->argv[i][0] == '=')
			{
				print_identifier_error(info, i);
				return (-1);
			}
			if (check_local_variable(info, i) == 0)
				add_to_list(info, info->lst, i);
			i++;
		}
	}
	else
		print_local(info->lst);
	return (0);
}
