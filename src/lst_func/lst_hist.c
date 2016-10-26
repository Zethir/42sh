/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:57:23 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/26 19:46:40 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

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

void	init_hist(t_hist **head, char *str)
{
	t_hist	*hist;
	t_hist	*cur;

	if (!(hist = (t_hist *)malloc(sizeof(t_hist))))
		return ;
	hist->prev = NULL;
	hist->next = NULL;
	hist->str = ft_strdup(str);
	if (*head == NULL)
	{
		*head = hist;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = hist;
	hist->prev = cur;
}

