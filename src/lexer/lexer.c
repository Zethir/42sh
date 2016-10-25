/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/25 15:53:24 by qdiaz            ###   ########.fr       */
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

int			check_lexer(t_shell *sh, t_lex *lex)
{
	char	*tmp;
	int		i;

	i = 0;
	while (lex->line[lex->hd])
	{
		tmp = ft_strsub(lex->line, lex->tl, lex->hd + 1);
		i = is_token(lex, lex->hd);
		if (check_parse_error(lex, i) == -1)
			return (-1);
		if (!lex->line[lex->hd + 1] && i == 0)
			if (add_token(lex, tmp, 13) == -1)
				return (-1);
		if (i > 0 && lex->hd > 0)
		{
			lex->hd = i;
			lex->tl = lex->hd;
		}
		else
			lex->hd++;
		if ((!lex->line[lex->hd] || !lex->line[lex->hd + 1]) && i != 0 &&
				lex->token->token_value != 13)
			get_missing_cmd(sh, lex);
		free(tmp);
	}
	return (0);
}
