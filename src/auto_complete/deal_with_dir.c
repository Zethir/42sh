/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:33:58 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/03 20:20:47 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static char	*join_if_dir_bis(char *dir, char *select_result, char **split_tmp)
{
	char	*tmp2;

	free(dir);
	select_result = join_cmd(split_tmp);
	tmp2 = ft_strdup(select_result);
	free(select_result);
	select_result = ft_strdup(tmp2);
	free(tmp2);
	ft_free_tab(split_tmp);
	return (select_result);
}

char		*join_if_dir(char *select_result, char *res, char *cmd)
{
	char	**split_tmp;
	char	*tmp2;
	char	*dir;
	int		i;

	i = 0;
	split_tmp = NULL;
	dir = deal_with_dir(cmd);
	if (!ft_strcmp(dir, "."))
	{
		free(dir);
		return (ft_strjoin(res, select_result));
	}
	split_tmp = ft_strsplit_ws(select_result);
	while (split_tmp[i])
	{
		tmp2 = ft_strjoin(dir, split_tmp[i]);
		free(split_tmp[i]);
		split_tmp[i] = ft_strdup(tmp2);
		free(tmp2);
		i++;
	}
	select_result = join_if_dir_bis(dir, select_result, split_tmp);
	return (select_result);
}

char		*split_if_dir(char *cmd)
{
	char	**split_res;
	char	*res;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		while (cmd[i])
			i++;
		if (cmd[i - 1] == '/')
			return (NULL);
		else
		{
			i = 0;
			split_res = ft_strsplit(cmd, '/');
			while (split_res[i])
				i++;
			res = ft_strdup(split_res[i - 1]);
			ft_free_tab(split_res);
			return (res);
		}
	}
	return (ft_strdup(cmd));
}

char		*deal_with_dir(char *cmd)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (!cmd)
		return (ft_strdup("."));
	if ((tmp = ft_strrchr(cmd, '/')) != NULL)
	{
		if (tmp[1] && tmp[1] != ' ')
			res = ft_strsub(cmd, 0, ft_strlen(cmd) - ft_strlen(tmp) + 1);
		else
			res = ft_strdup(cmd);
		return (res);
	}
	else
		return (ft_strdup("."));
}
