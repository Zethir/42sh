/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/09 18:39:18 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	parse_cmd(t_hub *info)
{
	t_job		*job;
	t_token		*token;
	int			stdio[3];

	token = info->lex->token;
	info->job = init_job();
	job = info->job;
	stdio[0] = 0;
	stdio[1] = 1;
	stdio[2] = 2;
	while (token)
	{
		if (token->token_value == PIPE)
			create_process(job, token, stdio);
		else if (token->token_value == AND || token->token_value == OR ||
				token->token_value == SEPARATOR)
		{
			create_process(job, token, stdio);
			create_job(job, token);
		}
		else
			token = hub_redir(job, token);
		token = token->next;
	}
	info->job = job;
}
