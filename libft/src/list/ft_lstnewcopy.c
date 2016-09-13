/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewcopy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:50:24 by tvallee           #+#    #+#             */
/*   Updated: 2015/01/15 16:55:38 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewcopy(void const *data, size_t data_size)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (data)
	{
		new->content = (void *)data;
		new->content_size = data_size;
		new->next = NULL;
	}
	return (new);
}
