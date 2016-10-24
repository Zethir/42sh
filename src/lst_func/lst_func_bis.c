/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:57:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 15:13:02 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

t_hist	*create_node(void)
{
	t_hist	*hist;

	if (!(hist = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	hist->str = NULL;
	hist->prev = NULL;
	hist->next = NULL;
	return (hist);
}

void	push_node_bis(t_hist **head, t_hist *new_hist)
{
	t_hist *cur;

	if (!*head)
	{
		*head = new_hist;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_hist;
	new_hist->prev = cur;
}

void	go_to_end_list(t_hist *hist)
{
	char	*str;

	str = ft_strdup(hist->str);
	while (hist->next)
		hist = hist->next;
	hist->str = ft_strdup(str);
	free(str);
}

