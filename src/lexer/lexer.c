/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/24 14:41:03 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

void		check_lexer(t_lex *lex)
{
	int		head;
	int		tail;

	head = 0;
	tail = 0;
	is_token(lex);
	lex->token = lex->token->next;
	while (lex->line[head])
	{
		if ()
		{
						
		}
		head++;
	}
	//while (lex->token)
	//{
	//	printf("lex->token->name = %s, value = %d\n", lex->token->name, lex->token->value);
	//	lex->token = lex->token->next;
	//}
}
