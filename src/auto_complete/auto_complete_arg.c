/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:28:20 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/03 21:44:27 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

char	*send_result(char *select_result, char *cmd)
{
	char	*str;

	if (!select_result)
		return (ft_strdup(cmd));
	str = join_if_dir(select_result, cmd);
	free(select_result);
	return (str);
}

char	*arg_exists(char **sel, char *cmd, int i)
{
	char	*tmp;
	char	*select_result;

	tmp = ft_strdup(sel[i - 1]);
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
