/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/08 16:19:00 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	parse_cmd(t_hub *info)
{
	while (info->lex->token)
	{
		if (info->lex->token->next)
		{
			/*if (info->lex->token->next->value == PIPE)
				exec_pipe(info);*/
			if (info->lex->token->next->value == 12)
				exec_cmd(info);
		}
		else
			exec_cmd(info);
		info->lex->token = info->lex->token->next;
		if (info->lex->token && info->lex->token->value != 0)
			info->lex->token = info->lex->token->next;
	}
}
