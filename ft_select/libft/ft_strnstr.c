/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:51:03 by qdiaz             #+#    #+#             */
/*   Updated: 2015/12/10 10:26:52 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[j] && i < n)
	{
		while (s2[k] == s1[j + k] && i + k < n)
		{
			if (s2[k + 1] == '\0')
				return ((char *)s1 + j);
			k++;
		}
		i++;
		j++;
	}
	return (NULL);
}
