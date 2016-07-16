/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:36:21 by qdiaz             #+#    #+#             */
/*   Updated: 2015/11/30 14:35:58 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)b;
	i = 0;
	while (n > 0)
	{
		ptr[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (b);
}
