/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 18:29:05 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/14 20:52:30 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		out_fd_close(t_hub *info, t_token *token, t_token *tmp)
{
	if (token->fd[0] != -1)
		info->closefd = token->fd[0];
	else
		info->closefd = 1;
	if (token->next)
	{
		tmp->cmd = ft_strjoin(tmp->cmd, token->next->cmd);
		return (1);
	}
	else
		return (0);
}

void		in_fd_close(void)
{
	printf("hello\n");
}
