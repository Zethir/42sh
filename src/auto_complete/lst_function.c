/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:58:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/04 15:17:06 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

static t_lst	*init_elem(char *argv)
{
	t_lst *ptr;

	if (!(ptr = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ptr->name = ft_strdup(argv);
	ptr->select = 0;
	ptr->save = NULL;
	ptr->len = ft_strlen(ptr->name);
	ptr->index += 1;
	ptr->next = NULL;
	return (ptr);
}

t_intel			*add_intel(t_intel *node, char *argv)
{
	t_lst	*ptr;

	if (node != NULL)
	{
		ptr = init_elem(argv);
		if (node->tail == NULL)
		{
			ptr->prev = NULL;
			node->head = ptr;
			node->tail = ptr;
		}
		else
		{
			node->tail->next = ptr;
			ptr->prev = node->tail;
			node->tail = ptr;
		}
		node->length++;
	}
	return (node);
}

t_intel			*init_lst(char **argv)
{
	t_intel	*node;
	size_t	i;

	i = 0;
	if (!(node = (t_intel *)malloc(sizeof(t_intel))))
		return (NULL);
	node->length = 0;
	node->head = NULL;
	node->tail = NULL;
	while (argv[i])
	{
		node = add_intel(node, argv[i]);
		i++;
	}
	return (node);
}
