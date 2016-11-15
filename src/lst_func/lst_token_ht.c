/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token_ht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:09:38 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/15 12:11:28 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

t_token_ht	*init_token_ht(void)
{
	t_token_ht	*token_ht;

	if (!(token_ht = (t_token_ht *)malloc(sizeof(t_lex))))
		return (NULL);
	token_ht->head = NULL;
	token_ht->tail = NULL;
	return (token_ht);
}
