/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:21:49 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/08 14:10:33 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	exec_pipe(t_hub *info)
{
	if (info->outfd == 0)
	{
		pipe(info->parse->pipefd);
		dup2(info->parse->pipefd[1], 1);
		close(info->parse->pipefd[0]);
		info->outfd = 1;
	}
	else if (info->outfd == 1)
	{
		dup2(info->parse->pipefd[0], 0);
		close(info->parse->pipefd[1]);
		info->outfd = 0;
	}
}
