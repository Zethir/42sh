/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:49:21 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/30 18:40:53 by qdiaz            ###   ########.fr       */
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
	test = ft_strdup(deal_with_dir(cmd));
	dir = opendir(test);
	while ((ret = readdir(dir)))
		i++;
	if (!(tab_files = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	closedir(dir);
	dir = opendir(test);
	free(test);
	while ((ret = readdir(dir)))
	{
		if (ft_strncmp(ret->d_name, ".", 1))
		{
			tab_files[i] = ft_strdup(ret->d_name);
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

	filenames = NULL;
	tmp = ft_strdup(first_occur(tab_files, cmd));
	i = first_occur_index(tab_files, cmd) + 1;
	while (tab_files[i])
	{
		if (!ft_strncmp(cmd, tab_files[i], ft_strlen(cmd)))
		{
			res = ft_strjoin(tmp, " ");
			free(tmp);
			tmp = ft_strjoin(res, tab_files[i]);
			free(res);
		}
		i++;
	}
	filenames = ft_strdup(tmp);
	free(tmp);
	return (filenames);
}

static char		*exec_select(char *cmd)
{
	char	**tab_for_exec;
	char	**tab_files;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tab_files = tab_to_select(cmd);
	cmd = split_if_dir(cmd);
	if (cmd)
	{
		tmp = join_for_select(tab_files, cmd);
		ft_free_tab(tab_files);
		if (!tmp)
			return (NULL);
		tab_for_exec = ft_strsplit_ws(tmp);
		if (!tab_for_exec[1])
		{
			free(tmp);
			tmp = ft_strdup(tab_for_exec[0]);
			ft_free_tab(tab_for_exec);
			tmp2 = deal_with_slash(tmp);
			free(tmp);
			return (tmp2);
		}
		tmp = main_select(ft_tablen(tab_for_exec), tab_for_exec);
		ft_free_tab(tab_for_exec);
		tmp2 = deal_with_slash(tmp);
		free(tmp);
		return (tmp2);
	}
	tmp = main_select(ft_tablen(tab_files), tab_files);
	tmp2 = deal_with_slash(tmp);
	free(tmp);
	ft_free_tab(tab_files);
	return (tmp2);
}

char			*auto_complete(char *cmd)
{
	char	**sel;
	char	*res;
	char	*tmp;
	char	*tmp2;
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
	ft_free_tab(sel);
	if (!tmp)
		return (cmd);
	tmp2 = ft_strdup(res);
	free(res);
	res = join_if_dir(tmp, tmp2, cmd);
	free(tmp2);
	free(tmp);
	return (res);
}
