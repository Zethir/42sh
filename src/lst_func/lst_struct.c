/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:17:17 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 16:12:37 by cboussau         ###   ########.fr       */
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
	if (!(sh->hist = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	sh->hist = create_node();
	deal_with_file(sh);
	return (sh);
}

void		init_stdio(t_shell *sh)
{
	if (!(sh->stdio = (int *)malloc(sizeof(int) * 3)))
		return ;
	sh->stdio[0] = 0;
	sh->stdio[1] = 1;
	sh->stdio[2] = 2;
	sh->closefd = -1;
}
