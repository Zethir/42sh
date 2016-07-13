/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:41:09 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/12 10:44:55 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	ft_putstr("---------> PRINT_TAB() <----------\n\n");
	while (tab[i])
	{
		ft_putnbr(i);
		ft_putstr("-> ");
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("\n---------> PRINT_TAB() END <---------\n\n");
}
