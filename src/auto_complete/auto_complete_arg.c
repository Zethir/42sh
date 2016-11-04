/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:28:20 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/04 16:23:39 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <select.h>

char	*send_result(char *select_result, char *cmd)
{
	char	*str;

	if (!select_result)
		return (ft_strdup(cmd));
	str = join_if_dir(select_result, cmd);
	free(select_result);
	return (str);
}

char	*arg_exists(char *cmd)
{
	char	*tmp;
	char	*select_result;

	tmp = ft_strdup(cmd);
	select_result = exec_select(tmp);
	free(tmp);
	tmp = send_result(select_result, cmd);
	return (tmp);
}

char	*arg_does_not_exist(char *cmd)
{
	char	*select_result;
	char	*tmp;

	select_result = exec_select(NULL);
	tmp = send_result(select_result, cmd);
	return (tmp);
}

char	**add_index_tab(char **sel)
{
	char	**res_tab;
	int		i;
	int		j;

	i = 0;
	j = ft_tablen(sel) + 1;
	if (!(res_tab = (char **)malloc(sizeof(char *) * ft_tablen(sel) + 1)))
		return (NULL);
	while (sel[i])
	{
		res_tab[i] = ft_strdup(sel[i]);
		i++;
	}
	res_tab[i] = ft_strdup("");
	i++;
	res_tab[i] = NULL;
	ft_free_tab(sel);
	return (res_tab);
}

char	*get_res_arg(char **sel, char *cmd, int i)
{
	char	**res_tab;
	char	*tmp;

	tmp = ft_strdup(sel[i - 1]);
	if (tmp && deal_with_cmd(cmd) == 2)
	{		
		free(sel[i - 1]);
		sel[i - 1] = arg_exists(tmp);
		free(tmp);
		tmp = join_tab(sel);
	}
	else
	{
		res_tab = add_index_tab(sel);
		res_tab[i] = arg_does_not_exist(NULL);
		free(tmp);
		tmp = join_tab(res_tab);
	//	if (res_tab)
	//		ft_free_tab(res_tab);
	}
	return (tmp);
}
