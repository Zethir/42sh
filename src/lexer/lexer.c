/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/26 17:54:50 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int	check_parse_error(t_lex *lex, int i)
{
	if (i < 0)
	{
		print_parse_error(lex->line[lex->hd]);
		return (-1);
	}
	else
		return (0);
}

t_token		*check_lexer(t_lex *lex, t_token_ht *token_ht, t_hist *hist)
{
	char		*tmp;
	int			i;

	i = 0;
	while (lex->line[lex->hd])
	{
		tmp = ft_strsub(lex->line, lex->tl, lex->hd + 1);
		i = is_token(lex, token_ht, lex->hd);
		if (check_parse_error(lex, i) == -1)
			return (NULL);
		if (!lex->line[lex->hd + 1] && i == 0)
			if ((token_ht = add_token(lex, token_ht, tmp, 13)) == NULL)
				return (NULL);
		if (i > 0 && lex->hd > 0)
		{
			lex->hd = i;
			lex->tl = lex->hd;
		}
		else
			lex->hd++;
		if ((!lex->line[lex->hd] || !lex->line[lex->hd + 1]) && i != 0 &&
				token_ht->tail->token_value != 13)
			get_missing_cmd(lex, token_ht, hist);
		free(tmp);
	}
	token_ht->tail->next = NULL;
	return (token_ht->head);
}
