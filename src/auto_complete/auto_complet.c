/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:49:21 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/03 19:18:13 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static char		**tab_to_select(char *cmd, int i)
{
	char			**tab_files;
	char			*directory;
	DIR				*dir;
	struct dirent	*ret;

	directory = deal_with_dir(cmd);
	if (!(dir = opendir(directory)))
		return (NULL);
	while ((ret = readdir(dir)))
		i++;
	if (!(tab_files = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	closedir(dir);
	dir = opendir(directory);
	free(directory);
	while ((ret = readdir(dir)))
	{
		if (ft_strncmp(ret->d_name, ".", 1))
			tab_files[i++] = ft_strdup(ret->d_name);
	}
	closedir(dir);
	tab_files[i] = NULL;
	return (tab_files);
}

char			*join_for_select(char **tab_files, char *cmd)
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

char			*exec_select(char *cmd)
{
	char	**tab_files;
	char	*frag_cmd;
	int		i;

	i = 0;
	if (!(tab_files = tab_to_select(cmd, i)))
		return (NULL);
	frag_cmd = split_if_dir(cmd);
	if (frag_cmd)
		return (exec_select_cmd(frag_cmd, tab_files));
	return (exec_select_null(tab_files));
}

char			*auto_complete(char *cmd)
{
	char	**sel;
	char	*res;
	int		i;

	i = 0;
	if (deal_with_cmd(cmd) == 0)
		return (ft_strdup(cmd));
	sel = ft_strsplit_ws(cmd);
	while (sel[i])
		i++;
	if (sel[i - 1] && deal_with_cmd(cmd) == 2)
		res = arg_exists(sel, cmd, i);
	else
		res = arg_does_not_exist(sel, cmd);
	ft_free_tab(sel);
	return (res);
}
