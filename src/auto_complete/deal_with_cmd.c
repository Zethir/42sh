/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:30:57 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/31 19:14:56 by qdiaz            ###   ########.fr       */
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

char		*join_cmd(char **sel)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	res = ft_strdup(sel[0]);
	while (sel[i])
	{
		if (ft_strcmp(sel[0], sel[i]))
		{
			tmp = ft_strjoin(res, " ");
			free(res);
			res = ft_strjoin(tmp, sel[i]);
			free(tmp);
		}
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

char		*join_cmd_bis(char **sel)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	res = ft_strdup(sel[0]);
	while (sel[i] && sel[i + 1])
	{
		if (ft_strcmp(sel[0], sel[i]))
		{
			tmp = ft_strjoin(res, " ");
			free(res);
			res = ft_strjoin(tmp, sel[i]);
			free(tmp);
		}
		i++;
	}
	tmp = ft_strjoin(res, " ");
	free(res);
	return (tmp);
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
