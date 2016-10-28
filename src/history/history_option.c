/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:04:26 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 15:10:49 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		option_c(t_shell *sh)
{
	int		fd;
	char	*str;

	if ((fd = open("/tmp/history", O_WRONLY | O_TRUNC, 0644)) == -1)
	{
		ft_putendl_fd("history : No such file or directory", 2);
		return ;
	}
	str = ft_strdup(sh->hist->str);
	free_hist(sh->head);
	sh->head = NULL;
	sh->hist = init_hist(str);
	push_hist(&sh->head, sh->hist);
	free(str);
}

void			do_option(t_shell *sh, char **cmd)
{
	if (ft_strcmp(cmd[1], "-c") == 0)
		option_c(sh);
	else if (ft_strcmp(cmd[1], "-d") == 0)
	{
		if (!cmd[2])
			ft_putendl_fd("Need entry number to execute", 2);
		else
			option_d(sh, cmd);
	}
	else if (ft_strcmp(cmd[1], "-r") == 0)
	{
		if (!cmd[2])
			option_r(sh);
		else
			ft_putendl_fd("Option [-r] doesn't need any arguments", 2);
	}
}
