/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:43:35 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/26 16:43:51 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void	get_missing_cmd(t_lex *lex, t_token_ht *token_ht, t_hist *hist)
{
	t_token	*token;

	token = token_ht->tail;
	if (token->token_value != R_TRUNC_FD && token->token_value !=
			R_TRUNC_FD_CLOSE && token->token_value != R_IN_FD &&
			token->token_value != R_IN_FD_CLOSE)
	{
		lex->line = ft_strjoin(hist->str, " ");
		lex->line = ft_strjoin(lex->line, deal_with_termcap(hist));
		ft_putchar('\n');
	}
}
