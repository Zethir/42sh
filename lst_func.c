/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/18 15:31:59 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	free_list(t_lst *node)
{
	while (node)
	{
		if (node->line)
			ft_strdel(&node->line);
		if (node->name)
			ft_strdel(&node->name);
		node = node->next;
	}
	free(node);
	node = NULL;
}

int		check_lst(t_lst *node)
{
	t_lst	*tmp;

	tmp = node;
	while (node)
	{
		if (node->line)
			return (1);
		else
			node = node->next;
	}
	node = tmp;
	return (0);
}

int		get_intel(t_lst *node, char *str)
{
	t_lst	*tmp;

	tmp = node;
	while (node)
	{
		if (ft_strcmp(node->name, str) == 0)
		{
			node = tmp;
			return (1);
		}
		node = node->next;
	}
	node = tmp;
	return (0);
}

void	push_node(t_lst *node, t_lst **head)
{
	t_lst	*tmp;

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

t_lst	*init_lst(char **env)
{
	t_lst	*node;
	t_lst	*head;

	head = NULL;
	while (*env)
	{
		if (!(node = (t_lst *)malloc(sizeof(t_lst))))
			return (NULL);
		node->next = NULL;
		node->line = ft_strdup(*env);
		node->name = ft_strsub(*env, 0, ft_strlen_char(*env, '='));
		if (ft_strccmp(*env, "USER=", '=') == 0)
			node->user = ft_strsub(*env, 5, ft_strlen(*env) - 5);
		if (ft_strncmp(*env, "HOME=", 5) == 0)
			node->home = ft_strchr(*env, '/');
		push_node(node, &head);
		env++;
	}
	return (head);
}
