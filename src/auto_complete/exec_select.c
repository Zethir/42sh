/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:25:57 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/03 20:19:22 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

char	*exec_select_one_result(char *filenames, char **tab_for_exec)
{
	char	*frag_cmd;

	free(filenames);
	filenames = ft_strdup(tab_for_exec[0]);
	ft_free_tab(tab_for_exec);
	frag_cmd = ft_strdup(filenames);
	free(filenames);
	return (frag_cmd);
}

char	*exec_select_cmd(char *frag_cmd, char **tab_files)
{
	char	**tab_for_exec;
	char	*filenames;
	char	*cmd;

	cmd = ft_strdup(frag_cmd);
	free(frag_cmd);
	filenames = join_for_select(tab_files, cmd);
	free(cmd);
	ft_free_tab(tab_files);
	if (!filenames)
		return (NULL);
	tab_for_exec = ft_strsplit_ws(filenames);
	if (!tab_for_exec[1])
		return (exec_select_one_result(filenames, tab_for_exec));
	free(filenames);
	filenames = main_select(ft_tablen(tab_for_exec), tab_for_exec);
	ft_free_tab(tab_for_exec);
	frag_cmd = ft_strdup(filenames);
	free(filenames);
	return (frag_cmd);
}

char	*exec_select_null(char **tab_files)
{
	char	*frag_cmd;
	char	*select_result;

	select_result = main_select(ft_tablen(tab_files), tab_files);
	ft_free_tab(tab_files);
	if (select_result)
	{
		frag_cmd = ft_strdup(select_result);
		free(select_result);
		return (frag_cmd);
	}
	return (NULL);
}
