/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:49:21 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/26 19:42:55 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static char		**tab_to_select(void)
{
	char			**tab_files;
	DIR				*dir;
	struct dirent	*ret;
	int				i;

	i = 0;
	dir = opendir(".");
	while ((ret = readdir(dir)))
		i++;
	if (!(tab_files = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	i = 0;
	dir = opendir(".");
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
	int		i;

	i = 0;
	filenames = ft_strdup(tab_files[0]);
	while (tab_files[i])
	{
		if (!ft_strncmp(cmd, tab_files[i], ft_strlen(cmd)))
		{
			tmp = ft_strjoin(filenames, " ");
			free(filenames);
			filenames = ft_strjoin(tmp, tab_files[i]);
			free(tmp);
		}
		i++;
	}
	return (filenames);
}

static char		*exec_select(char *cmd)
{
	char	**tab_for_exec;
	char	**tab_files;

	tab_files = tab_to_select();
	if (cmd)
	{
		tab_for_exec = ft_strsplit_ws(join_for_select(tab_files, cmd));
		return (main_select(ft_tablen(tab_for_exec), tab_for_exec));
	}
	return (main_select(ft_tablen(tab_files), tab_files));
}

char			*auto_complete(char *cmd)
{
	char	**sel;
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	sel = ft_strsplit_ws(cmd);
	while (sel[i])
		i++;
	if (sel[i - 1] && i > 1)
	{
		tmp = ft_strdup(exec_select(sel[i -1]));
		res = ft_strjoin(sel[0], " ");
		res = ft_strjoin(res, tmp);
		return (res);
	}
	else 
	{
		tmp = ft_strdup(exec_select(NULL));
		res = ft_strjoin(sel[0], " ");
		res = ft_strjoin(res, tmp);
		return (res);
	}
}
