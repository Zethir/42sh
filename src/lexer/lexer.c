/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/26 15:40:06 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void		check_lexer(t_lex *lex)
{
	int		head;
	int		tail;
	int		i;
	int		token;

	head = 0;
	tail = 0;
	i = 0;
	token = 0;
	while (lex->line[head])
	{
		if ((token = is_token(lex, head)) > 0)
		{
			lexer_cmd(lex, head - 1, tail, i);
			head = token;
			i++;
			tail = head;
		}
		else if ((token = is_token(lex, head)) < 0)
		{
			ft_putstr_fd("42sh: parse error near `", 2);
			ft_putchar_fd(lex->line[head], 2);
			ft_putendl_fd("'", 2);
		}
		head++;
	}
	/*while (lex->token)
	{
		printf("lex->token->name = %s, value = %d\n", lex->token->name, lex->token->value);
		lex->token = lex->token->next;
	}*/
}
