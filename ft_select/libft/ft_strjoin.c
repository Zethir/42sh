/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:01:46 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/12 17:42:25 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str != NULL)
	{
		ft_strcat(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
