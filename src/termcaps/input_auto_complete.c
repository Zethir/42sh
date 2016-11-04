/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_auto_complete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:51:06 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/04 13:50:36 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

char			*join_tab(char **arg)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp2 = ft_strdup(arg[0]);
	i = 1;
	while (arg[i])
	{
		tmp = ft_strjoin(tmp2, " ");
		free (tmp2);
		tmp2 = ft_strjoin(tmp, arg[i]);
		free (tmp);
		i++;
	}
	return (tmp2);
}

static void		arg_is_dir(t_prompt *prompt, char **arg, int i)
{
	char	*tmp;

	tmp = ft_strdup(arg[i - 1]);
	free(arg[i - 1]);
	arg[i - 1] = ft_strjoin(tmp, "/");
	free(tmp);
	tmp = join_tab(arg);
	ft_strclr(prompt->cmd);
	ft_strcpy(prompt->cmd, tmp);
	prompt->i = ft_strlen(prompt->cmd);
	prompt_print(prompt, 1);
	free(tmp);
}

static int		check_if_arg_is_dir(t_prompt *prompt)
{
	char	**arg;
	DIR		*str;
	int		i;

	i = 0;
	arg = ft_strsplit_ws(prompt->cmd);
	while (arg[i])
		i++;
	if ((str = opendir(arg[i - 1])) != NULL &&
			arg[i - 1][ft_strlen(arg[i - 1]) - 1] != '/')
	{
		arg_is_dir(prompt, arg, i);
		closedir(str);
		if (arg)
			ft_free_tab(arg);
		return (1);
	}
	if (arg)
		ft_free_tab(arg);
	return (0);
}

void	start_auto_complete(t_prompt *prompt, char *buff)
{
	char	*res;

	if (buff[0] == 9 && prompt->cmd[0])
	{
		if ((size_t)prompt->i < ft_strlen(prompt->cmd))
		{
			prompt->i = ft_strlen(prompt->cmd);
			prompt_print(prompt, 1);
		}
		else
		{
			if (check_if_arg_is_dir(prompt) == 1)
				return ;
			res = auto_complete(prompt->cmd);
			ft_strcpy(prompt->cmd, res);
			if (res)
				free(res);
			prompt->i = ft_strlen(prompt->cmd);
			prompt_print(prompt, 1);
		}
	}
}
