/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_job_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:41:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/19 16:07:27 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	token_linker(t_hub *info, t_job *job, t_token *token)
{
	create_process(job, token, info);
	init_stdio(info);
	create_job(job, token);
	job->process = NULL;
}

void	token_pipe(t_hub *info, t_job *job, t_token *token)
{
	create_process(job, token, info);
	init_stdio(info);
}

void	get_missing_cmd(t_hub *info, t_lex *lex)
{
	ft_putstr("cmd||filename> ");
	lex->line = ft_strjoin(info->node->str, " ");
	lex->line = ft_strjoin(lex->line, deal_with_termcap(info));
	ft_putchar('\n');
}
