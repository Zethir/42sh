/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:10:14 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 19:19:01 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

t_lex	*init_lexer_struct(void)
{
	t_lex	*lex;

	if (!(lex = (t_lex *)malloc(sizeof(t_lex))))
		return (NULL);
	if (!(lex->fd = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	lex->line = NULL;
	lex->hd = 0;
	lex->tl = 0;
	lex->fd[0] = -1;
	lex->fd[1] = -1;
	return (lex);
}
