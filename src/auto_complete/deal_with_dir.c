/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:33:58 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/31 19:14:58 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

char	*join_if_dir(char *tmp, char *res, char *cmd)
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
		return (ft_strjoin(res, tmp));
	}
	split_tmp = ft_strsplit_ws(tmp);
	while (split_tmp[i])
	{
		tmp2 = ft_strjoin(dir, split_tmp[i]);
		free(split_tmp[i]);
		split_tmp[i] = ft_strdup(tmp2);
		free(tmp2);
		i++;
	}
	free(dir);
	tmp = join_cmd(split_tmp);
	tmp2 = ft_strdup(tmp);
	free(tmp);
	tmp = deal_with_slash(tmp2);
	free(tmp2);
	ft_free_tab(split_tmp);
	return (tmp);
}

char	*deal_with_slash(char *cmd)
{
	char	**split_res;
	char	*tmp;
	DIR		*dir;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	split_res = ft_strsplit_ws(cmd);
	while (split_res[i])
	{
		if ((dir = opendir(split_res[i])) != NULL)
		{
			tmp = ft_strjoin(split_res[i], "/");
			free(split_res[i]);
			split_res[i] = ft_strdup(tmp);
			free(tmp);
			closedir(dir);
		}
		i++;
	}
	cmd = join_cmd(split_res);
	ft_free_tab(split_res);
	return (cmd);
}

char	*split_if_dir(char *cmd)
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

char	*deal_with_dir(char *cmd)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (!cmd)
		return (ft_strdup("."));
	if ((tmp = ft_strrchr(cmd, '/')) != NULL)
	{
		if (tmp[1])
			res = ft_strsub(cmd, 0, ft_strlen(cmd) - ft_strlen(tmp) + 1);
		else
			res = ft_strdup(cmd);
		return (res);
	}
	else
		return (ft_strdup("."));
}
