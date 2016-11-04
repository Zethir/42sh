/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:30:57 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/04 16:21:16 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			first_occur_index(char **tab_files, char *cmd)
{
	int		i;

	i = 0;
	while (tab_files[i])
	{
		if (!ft_strncmp(cmd, tab_files[i], ft_strlen(cmd)))
			return (i);
		i++;
	}
	return (0);
}

char		*first_occur(char **tab_files, char *cmd)
{
	int		i;

	i = 0;
	while (tab_files[i])
	{
		if (!ft_strncmp(cmd, tab_files[i], ft_strlen(cmd)))
			return (tab_files[i]);
		i++;
	}
	return (cmd);
}

char		*join_cmd(char **arg)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 1;
	res = ft_strdup(arg[0]);
	while (arg[i])
	{
		tmp = ft_strjoin(res, " ");
		free(res);
		res = ft_strjoin(tmp, arg[i]);
		free(tmp);
		i++;
	}
	tmp = ft_strdup(res);
	free(res);
	if (!ft_strchr(tmp, '/'))
		res = ft_strjoin(tmp, " ");
	else
		res = ft_strdup(tmp);
	free(tmp);
	return (res);
}

int			deal_with_cmd(char *cmd)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			cnt++;
		i++;
	}
	if (cnt == 0)
		return (0);
	if (cmd[i - 1] == ' ')
		return (1);
	else
		return (2);
}
