/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:43:35 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/05 12:08:34 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void	get_missing_cmd(t_lex *lex, t_token_ht *token_ht, t_shell *sh)
{
	t_token	*token;
	char	*tmp;
	char	*tmp2;

	token = token_ht->tail;
	tmp = NULL;
	if (token->token_value != R_TRUNC_FD && token->token_value !=
			R_TRUNC_FD_CLOSE && token->token_value != R_IN_FD &&
			token->token_value != R_IN_FD_CLOSE)
	{
		tmp = ft_strjoin(sh->hist->str, " ");
		free(lex->line);
		tmp2 = termcap_heredoc(sh);
		lex->line = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
		free(sh->hist->str);
		sh->hist->str = ft_strdup(lex->line);
		ft_putchar('\n');
	}
}
