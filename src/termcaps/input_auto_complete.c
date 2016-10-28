/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_auto_complete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:51:06 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/28 17:22:57 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	start_auto_complete(t_prompt *prompt, char *buff)
{
	if (buff[0] == 9 && prompt->cmd[0])
	{
		ft_strcpy(prompt->cmd, auto_complete(prompt->cmd));
		prompt->i = ft_strlen(prompt->cmd);
		prompt_print(prompt, buff);
	}
}
