/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:28:20 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/03 20:18:01 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

char	*send_result(char *select_result, char *res, char *cmd)
{
	char	*str;
	char	*tmp;

	if (!select_result)
	{
		free(res);
		return (ft_strdup(cmd));
	}
	tmp = ft_strdup(res);
	free(res);
	str = join_if_dir(select_result, tmp, cmd);
	free(tmp);
	free(select_result);
	return (str);
}

char	*arg_exists(char **sel, char *cmd, int i)
{
	char	*tmp;
	char	*res;
	char	*select_result;

	tmp = ft_strdup(sel[i - 1]);
	select_result = exec_select(tmp);
	free(tmp);
	res = join_cmd_bis(sel);
	tmp = send_result(select_result, res, cmd);
	return (tmp);
}

char	*arg_does_not_exist(char **sel, char *cmd)
{
	char	*res;
	char	*select_result;
	char	*tmp;

	select_result = exec_select(NULL);
	res = join_cmd(sel);
	tmp = send_result(select_result, res, cmd);
	return (tmp);
}
