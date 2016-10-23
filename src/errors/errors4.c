/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:35:40 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/23 10:29:48 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	print_parse_error(t_lex *lex)
{
	ft_putstr_fd("21sh: parse error near `", 2);
	ft_putchar_fd(lex->line[lex->hd], 2);
	ft_putendl_fd("'", 2);
}
