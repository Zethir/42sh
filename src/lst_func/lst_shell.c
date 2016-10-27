/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 19:29:20 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 15:34:55 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

t_shell		*stock_struct(t_shell *sh, int i)
{
	static t_shell *tmp = NULL;

	if (i == 0)
		tmp = sh;
	return (tmp);
}

t_shell		*init_struct(char **env)
{
	t_shell	*sh;

	if (!(sh = (t_shell *)malloc(sizeof(t_shell))))
		return (NULL);
	sh->env = init_env(env);
	deal_with_file(sh);
	sh->hist = sh->hist->next;
	sh->hist = create_hist();
	push_hist(&sh->head, sh->hist);
	return (sh);
}

void		init_stdio(t_shell *sh)
{
	sh->stdio[0] = 0;
	sh->stdio[1] = 1;
	sh->stdio[2] = 2;
	sh->closefd = -1;
}
