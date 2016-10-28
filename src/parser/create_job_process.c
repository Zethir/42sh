/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_job_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:41:34 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 13:59:27 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	token_linker(t_shell *sh, t_job **job, t_process **p, t_token *token)
{
	create_process(p, token, sh);
	create_job(job, p, token);
	init_stdio(sh);
	*p = NULL;
}

void	token_pipe(t_shell *sh, t_process **process, t_token *token)
{
	create_process(process, token, sh);
	init_stdio(sh);
}
