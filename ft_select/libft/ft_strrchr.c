/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:29:35 by qdiaz             #+#    #+#             */
/*   Updated: 2015/11/30 14:39:43 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp_s;

	tmp_s = s;
	tmp_s += ft_strlen(s);
	while (*tmp_s != (char)c && tmp_s != s)
		tmp_s--;
	if (*tmp_s == (char)c)
		return ((char *)tmp_s);
	return (NULL);
}
