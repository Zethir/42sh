/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:28:20 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/17 12:16:43 by cboussau         ###   ########.fr       */
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

char	*add_index_tab(char **sel)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strdup("");
	tmp2 = arg_does_not_exist(tmp);
	free(tmp);
	tmp = join_tab(sel);
	tmp3 = ft_strjoin(tmp, " ");
	free(tmp);
	tmp = ft_strjoin(tmp3, tmp2);
	free(tmp2);
	free(tmp3);
	return (tmp);
}

char	*get_res_arg(char **sel, char *cmd, int i)
{
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
		free(tmp);
		tmp = add_index_tab(sel);
	}
	return (tmp);
}
