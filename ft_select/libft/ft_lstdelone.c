/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:21:05 by qdiaz             #+#    #+#             */
/*   Updated: 2015/12/09 11:43:06 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL || alst != NULL || del != NULL)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
