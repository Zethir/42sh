/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caca.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:08:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/05/28 14:27:06 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct		s_dlist
{
	char			*str;
	int				i;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

t_dlist	*create_node()
{
	t_dlist	*node;

	if (!(node = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	node->str = NULL;
	node->i = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_node_bis(t_dlist **head, t_dlist *new_node)
{
	t_dlist *cur;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
}

int		main()
{
	int		j;
	t_dlist *node;
	t_dlist	*tmp;
	char	*str[] = {"hello", "prout", "caca", "chiotte", "yop", "lol", "fewf", "wefwef", "wfw", "fgrg"};

	j = 0;
	node = create_node();
	tmp = node;
	while (j != 10)
	{
		node->str = str[j];
		j++;
		push_node_bis(&node, create_node());
		node = node->next;
	}
	while (node)
	{
		printf("node->str = %s\n", node->str);
		node = node->prev;
	}
	node = tmp;
	while (node)
	{
		printf("node->str = %s\n", node->str);
		node = node->next;
	}

	return (0);
}
