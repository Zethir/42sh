/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:10:35 by qdiaz             #+#    #+#             */
/*   Updated: 2015/12/09 10:51:55 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*strdst;
	const char	*strsrc;
	int			i;

	strdst = (char *)dst;
	strsrc = (const char *)src;
	i = 0;
	while (n > 0)
	{
		strdst[i] = strsrc[i];
		i++;
		n--;
	}
	return (strdst);
}
