/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:40:54 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/26 18:09:59 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void		check_lexer(t_lex *lex)
{
	int		head;
	int		i;
	int		tail;
	int		j;

	tail = 0;
	head = 0;
	i = 0;
	j = 1;
	while (lex->line[head])
	{
		i = is_token(lex, head);
		if (i < 0)
		{
			ft_putstr_fd("42sh: parse error near `", 2);
			ft_putchar_fd(lex->line[head], 2);
			ft_putendl_fd("'", 2);
			return ;
		}
		if (!lex->line[head + 1])
			add_cmd(lex->cmd, ft_strsub(lex->line, tail, head + 1), j);
		if (i > 0)
		{
			add_cmd(lex->cmd, ft_strsub(lex->line, tail, head - tail), j);
			j++;
			head = i;
			tail = head;
		}
		else
			head++;
	}
	lex->token = lex->token->next;
	lex->cmd = lex->cmd->next;
	while (lex->token)
	{
		printf("lex->token->name = %s, value = %d\n", lex->token->name, lex->token->value);
		lex->token = lex->token->next;
	}
	while (lex->cmd)
	{
		printf("lex->token->str = %s, index = %d\n", lex->cmd->str, lex->cmd->index);
		lex->cmd = lex->cmd->next;
	}
}
