/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 18:19:21 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	free_env(t_env *node)
{
	while (node)
	{
		if (node->line)
			free(node->line);
		if (node->name)
			free(node->name);
		node = node->next;
	}
	free(node);
	node = NULL;
}

void	free_hist(t_hist *node)
{
	while (node)
	{
		if (node->str)
			free(node->str);
		node = node->next;
	}
	free(node);
	node = NULL;
}

void	free_shell(t_shell *sh)
{
	if (sh->stdio)
		free(sh->stdio);
	sh->closefd = 0;
	free(sh);
	sh = NULL;
}
