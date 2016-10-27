/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_hist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:31:25 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 17:30:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	push_hist(t_hist **head, t_hist *new_hist)
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

t_hist	*create_hist(void)
{
	t_hist	*hist;

	if (!(hist = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	hist->str = NULL;
	hist->prev = NULL;
	hist->next = NULL;
	return (hist);
}

t_hist	*init_hist(char *str)
{
	t_hist	*hist;

	if (!(hist = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	hist->prev = NULL;
	hist->next = NULL;
	hist->str = ft_strdup(str);
	return (hist);
}
