/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/26 15:45:58 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	free_env(t_env *node)
{
	t_env	*tmp;

	while (node)
	{
		if (node->line)
			free(node->line);
		if (node->name)
			free(node->name);
		if (node->home)
			free(node->home);
		if (node->user)
			free(node->user);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(node);
	node = NULL;
}

void	free_hist(t_hist *node)
{
	t_hist	*tmp;

	while (node)
	{
		if (node->str)
			free(node->str);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(node);
	node = NULL;
}

void	free_shell(t_shell *sh)
{

	free_env(sh->env);
	free_hist(sh->hist);
	sh->closefd = 0;
	free(sh);
	sh = NULL;
}
