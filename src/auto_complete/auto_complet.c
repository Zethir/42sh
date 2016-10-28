/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:49:21 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/28 19:36:19 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static char		**tab_to_select(char *cmd)
{
	char			**tab_files;
	DIR				*dir;
	struct dirent	*ret;
	int				i;
	char			*test;

	i = 0;
	test = deal_with_dir(cmd);
	dir = opendir(test);
	while ((ret = readdir(dir)))
		i++;
	if (!(tab_files = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	dir = opendir(test);
	while ((ret = readdir(dir)))
	{
		if (ft_strncmp(ret->d_name, ".", 1))
		{
			tab_files[i] = ret->d_name;
			i++;
		}
	}
	closedir(dir);
	tab_files[i] = NULL; 
	return (tab_files);
}

static char		*join_for_select(char **tab_files, char *cmd)
{
	char	*filenames;
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	tmp = ft_strdup(tab_files[0]);
	filenames = NULL;
	while (tab_files[i])
	{
		if (!ft_strncmp(cmd, tab_files[i], ft_strlen(cmd)))
		{
			res = ft_strjoin(tmp, " ");
			free(tmp);
			filenames = ft_strjoin(res, tab_files[i]);
			free(res);
		}
		i++;
	}
	return (filenames);
}

static char		*exec_select(char *cmd)
{
	char	**tab_for_exec;
	char	**tab_files;
	char	*tmp;

	tab_files = tab_to_select(cmd);
	cmd = split_if_dir(cmd);
	if (cmd)
	{
		tmp = join_for_select(tab_files, cmd);
		if (!tmp)
			return (NULL);
		tab_for_exec = ft_strsplit_ws(tmp);
		if (!tab_for_exec[2])
			return (deal_with_slash(tab_for_exec[1]));
		tmp = main_select(ft_tablen(tab_for_exec), tab_for_exec);
		return (deal_with_slash(tmp));
	}
	tmp = main_select(ft_tablen(tab_files), tab_files);
	return (deal_with_slash(tmp));
}

char			*auto_complete(char *cmd)
{
	char	**sel;
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	if (deal_with_cmd(cmd) == 0)
		return (cmd);
	sel = ft_strsplit_ws(cmd);
	while (sel[i])
		i++;
	if (sel[i - 1] && deal_with_cmd(cmd) == 2)
	{
		tmp = exec_select(sel[i - 1]);
		res = join_cmd_bis(sel);
	}
	else 
	{
		tmp = exec_select(NULL);
		res = join_cmd(sel);
	}
	if (!tmp)
		return (cmd);
	res = join_if_dir(tmp, res, cmd);
	return (res);
}
