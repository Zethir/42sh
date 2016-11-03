/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_auto_complete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:51:06 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/03 19:46:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	start_auto_complete(t_prompt *prompt, char *buff)
{
	char	*res;

	if (buff[0] == 9 && prompt->cmd[0])
	{
		if ((size_t)prompt->i < ft_strlen(prompt->cmd))
		{
			prompt->i = ft_strlen(prompt->cmd);
			prompt_print(prompt, 1);
		}
		else
		{
			res = auto_complete(prompt->cmd);
			ft_strcpy(prompt->cmd, res);
			if (res)
				free(res);
			prompt->i = ft_strlen(prompt->cmd);
			prompt_print(prompt, 1);
		}
	}
}
