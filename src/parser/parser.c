/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:19:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/10 16:34:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void	print_job_process(t_job *job)
{
	while (job)
	{
		if (job->linker == 0)
			job = job->next;
		while (job->process)
		{
			printf("process->cmd = %s\n", job->process->cmd);
			job->process = job->process->next;
		}
		printf("linker = %d\n", job->linker);
		job = job->next;
	}
}

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
			job->process = NULL;
		}
		else
			token = hub_redir(job, token);
		token = token->next;
	}
	info->job = job;
	print_job_process(job);
}
