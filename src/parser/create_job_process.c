/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_job_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:41:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/25 14:28:39 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	token_linker(t_shell *sh, t_job *job, t_token *token)
{
	create_process(job, token, sh);
	create_job(job, token);
	job->process = NULL;
}

void	token_pipe(t_shell *sh, t_job *job, t_token *token)
{
	create_process(job, token, sh);
}
