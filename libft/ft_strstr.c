/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:53:27 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 11:00:46 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	if (s1[i] && s2[j])
	{
		while (s1[i])
		{
			while (s2[j] == s1[i + j])
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				j++;
			}
			i++;
			j = 0;
		}
	}
	return (NULL);
}
