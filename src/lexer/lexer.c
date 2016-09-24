/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/24 15:01:41 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void		check_lexer(t_lex *lex)
{
	//int		head;
	//int		tail;

	/*head = 0;
	tail = 0;
	is_token(lex);
	while (lex->line[head])
	{
		if ()
		{
						
		}
		head++;
	}*/
	lex->token = lex->token->next;
	while (lex->token)
	{
		printf("lex->token->name = %s, value = %d\n", lex->token->name, lex->token->value);
		lex->token = lex->token->next;
	}
}
