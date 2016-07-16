/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:39:22 by qdiaz             #+#    #+#             */
/*   Updated: 2015/12/04 11:40:59 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	return (str);
}
