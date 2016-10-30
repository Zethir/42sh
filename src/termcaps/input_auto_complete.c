/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_auto_complete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:51:06 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/30 18:18:19 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	start_auto_complete(t_prompt *prompt, char *buff)
{
	char	*res;

	if (buff[0] == 9 && prompt->cmd[0])
	{
		res = auto_complete(prompt->cmd);
		ft_strcpy(prompt->cmd, res);
		if (res)
			free(res);
		prompt->i = ft_strlen(prompt->cmd);
		prompt_print(prompt, buff);
	}
}
