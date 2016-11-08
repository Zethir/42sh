/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:16:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 18:24:12 by cboussau         ###   ########.fr       */
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
	if (sh->env)
		free_env(sh->env);
	if (sh->head)
		free_hist(sh->head);
	sh->closefd = 0;
	free(sh);
	sh = NULL;
}
