/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 15:37:22 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	parse_cmd(lex)
{
	if (lex->token->value = 0)
		exec_cmd(lex);
	/*else if (lex->token->value == 1)
		exec_and(lex);
	else if (lex->token->value == 2)
		exec_or(lex);
	else if (lex->token->value == 3)
		exec_pipe(lex);
	else if (lex->token->value == 4)
		exec_radd(lex);
	else if (lex->token->value == 5)
		exec_rout(lex);
	else if (lex->token->value == 6)
		exec_routfdclose(lex);
	else if (lex->token->value == 7)
		exec_outfd(lex);
	else if (lex->token->value == 8)
		exec_heredoc(lex);
	else if (lex->token->value == 9)
		exec_in(lex);
	else if (lex->token->value == 10)
		exec_infdclose(lex);
	else if (lex->token->value == 11)
		exec_infd(lex);*/
	else
		return ;
}
