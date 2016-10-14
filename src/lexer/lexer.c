/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/14 19:53:34 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

/*static void		temp_print_lst(t_lex *lex)
{
	while (lex->token)
	{
		printf("lex->token->name = %s, value = %d\n", lex->token->name,
				lex->token->value);
		lex->token = lex->token->next;
	}
}*/

void		check_lexer(t_lex *lex)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (lex->line[lex->hd])
	{
		i = is_token(lex, lex->hd);
		if (i < 0)
		{
			print_parse_error(lex);
			return ;
		}
		if (!lex->line[lex->hd + 1] && i == 0)
			add_token(lex, ft_strsub(lex->line, lex->tl, lex->hd + 1), 13);
		if (i > 0 && lex->hd > 0)
		{
			j++;
			lex->hd = i;
			lex->tl = lex->hd;
		}
		else
			lex->hd++;
	}
	//temp_print_lst(lex);
}
