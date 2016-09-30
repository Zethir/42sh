/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/30 16:51:07 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void		temp_print_lst(t_lex *lex)
{
	while (lex->token)
	{
		printf("lex->token->name = %s, value = %d\n", lex->token->name,
				lex->token->value);
		lex->token = lex->token->next;
	}
	while (lex->cmd)
	{
		printf("lex->cmd->cmd = %s, index = %d\n", lex->cmd->argv[0],
				lex->cmd->index);
		lex->cmd = lex->cmd->next;
	}
}

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
			add_cmd(lex, ft_strsub(lex->line, lex->tl, lex->hd + 1), j);
		if (i > 0)
		{
			add_cmd(lex, ft_strsub(lex->line, lex->tl, lex->hd - lex->tl), j);
			j++;
			lex->hd = i;
			lex->tl = lex->hd;
		}
		else
			lex->hd++;
	}
	temp_print_lst(lex);
}
