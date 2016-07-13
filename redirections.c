/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:38:51 by cboussau          #+#    #+#             */
/*   Updated: 2016/04/20 18:52:47 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	redirection_out(t_struct *ptr, int fd, int i)
{
	int		ret;
	
	i += 1;
	if (ft_strstr(ptr->arg[i - 1], ">>") != NULL)
	{
		if ((ret = open(ptr->arg[i], O_WRONLY |
						O_CREAT | O_APPEND, 0644)) == -1)
		{
			perror(ptr->arg[i]);
			exit(-1);
		}
		dup2(ret, fd);
		close(ret);
	}
	else
	{
		if ((ret = open(ptr->arg[i], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		{
			perror(ptr->arg[i]);
			exit (-1);
		}
		dup2(ret, fd);
		close(ret);
	}
}

static void	deal_with_redirectionbis(t_struct *ptr, int i)
{
	if (ft_strcmp(ptr->arg[i], "<") == 0)
		redirection_in(ptr, 0, i);	
	else if (ft_strcmp(ptr->arg[i], "<<") == 0)
		data_series(ptr, i);
	else if (ft_strcmp(ptr->arg[i], "<1") == 0)
		redirection_in(ptr, 0, i);
	else if (ft_strcmp(ptr->arg[i], "<<1") == 0)
		data_series(ptr, i);
	else if (ft_strcmp(ptr->arg[i], "&>") == 0)
		redirection_err_out(ptr, i);
	else if (ft_strcmp(ptr->arg[i], ">&") == 0)
		redirection_out(ptr, 1, i);
	else if (ft_strcmp(ptr->arg[i], "2>&") == 0)
		redirection_out(ptr, 2, i);
	else if (ft_strcmp(ptr->arg[i], "<&") == 0)
		redirection_in(ptr, 0, i);
	else if (ft_strcmp(ptr->arg[i], ">&-") == 0)
		close(1);
}
	
void		deal_with_redirection(t_struct *ptr)
{
	int			i;
	char		**str;
	
	i = 1;
	str = save_command(ptr);
	while (ptr->arg[i])
	{
		if (ft_strcmp(ptr->arg[i], ">") == 0)
			redirection_out(ptr, 1, i);
		else if (ft_strcmp(ptr->arg[i], ">>") == 0)
			redirection_out(ptr, 1, i);
		else if (ft_strcmp(ptr->arg[i], "1>") == 0)
			redirection_out(ptr, 1, i);
		else if (ft_strcmp(ptr->arg[i], "1>>") == 0)
			redirection_out(ptr, 1, i);
		else if (ft_strcmp(ptr->arg[i], "2>") == 0)
			redirection_out(ptr, 2, i);
		else if (ft_strcmp(ptr->arg[i], "2>>") == 0)
			redirection_out(ptr, 2, i);
		else
			deal_with_redirectionbis(ptr, i);
		i++;
	}
	exec_cmd(ptr, str);
	free(str);
}
