/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:51:57 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/16 13:00:20 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_strnew(ft_strlen(s1) + (ft_strlen(s2) * len) + 1);
	if (str)
	{
		ft_strcat(str, s1);
		while (i < len)
		{
			ft_strcat(str, s2);
			i++;
		}
	}
	return (str);
}
