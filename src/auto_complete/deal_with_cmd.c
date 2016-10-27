/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:30:57 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/27 19:47:01 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>


char     *join_cmd(char **sel)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	res = ft_strdup(sel[0]);
	while (sel[i])
	{
		tmp = ft_strjoin(res, " ");
		free(res);
		res = ft_strjoin(tmp, sel[i]);
		free(tmp);
		i++;
	}
	res = ft_strjoin(res, " ");
	return (res);
}

char     *join_cmd_bis(char **sel)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	res = ft_strdup(sel[0]);
	while (sel[i] && sel[i + 1])
	{
		tmp = ft_strjoin(res, " ");
		free(res);
		res = ft_strjoin(tmp, sel[i]);
		free(tmp);
		i++;
	}
	res = ft_strjoin(res, " ");
	return (res);
}

int		deal_with_cmd(char *cmd)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			cnt++;;
		i++;
	}
	if (cnt == 0)
		return (0);
	if (cmd[i - 1] == ' ')
		return (1);
	else
		return (2);
}
