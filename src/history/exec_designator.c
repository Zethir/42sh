/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_designator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:33:14 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 19:34:07 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		add_lst(t_shell *sh, char **tabl)
{
	char	**env;
	char	*tmp;
	int		i;

	i = 1;
	sh->hist->str = ft_strdup(tabl[0]);
	ft_putstr(tabl[0]);
	ft_putchar(' ');
	while (tabl[i])
	{
		ft_putstr(tabl[i]);
		tmp = ft_strjoin(sh->hist->str, " ");
		free(sh->hist->str);
		sh->hist->str = ft_strjoin(tmp, tabl[i]);
		free(tmp);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	env = get_env(sh->env);
	exec_env(sh, sh->hist->str, env);
	ft_free_tab(env);
}

void			exec_cmd_lst(t_shell *sh, char **cmd, char *line)
{
	char	**tabl;
	char	*tmp;
	int		i;

	i = 1;
	while (cmd[i])
	{
		tmp = ft_strjoin(line, " ");
		free(line);
		line = ft_strjoin(tmp, cmd[i]);
		free(tmp);
		i++;
	}
	tabl = ft_strsplit_ws(line);
	add_lst(sh, tabl);
	ft_free_tab(tabl);
}
