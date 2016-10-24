/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:28:53 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 13:34:34 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	deal_with_delete(t_prompt *prompt, char *buff)
{
	if (DELETE && prompt->cmd[prompt->i])
	{
		ft_memmove(prompt->cmd + prompt->i, prompt->cmd + prompt->i + 1,
				ft_strlen(prompt->cmd + prompt->i + 1) + 1);
		prompt_print(prompt, buff);
	}
}

void	deal_with_backspace(t_prompt *prompt, char *buff)
{
	if (BACK_SPACE && prompt->i > 0)
	{
		prompt->i--;
		ft_memmove(prompt->cmd + prompt->i, prompt->cmd + prompt->i + 1,
				ft_strlen(prompt->cmd + prompt->i + 1) + 1);
		prompt_print(prompt, buff);
	}
}

void	deal_with_space(t_prompt *prompt, char *buff)
{
	if (WHITE_SPACE)
	{
		ft_memmove(prompt->cmd + prompt->i + 1, prompt->cmd + prompt->i,
			ft_strlen(prompt->cmd + prompt->i) + 1);
		prompt->cmd[prompt->i] = ' ';
		prompt->i++;
		prompt_print(prompt, buff);
	}
}

void	deal_with_charac(t_prompt *prompt, char *buff)
{
	if (CHARACTERE)
	{
		ft_memmove(prompt->cmd + prompt->i + 1, prompt->cmd + prompt->i,
				ft_strlen(prompt->cmd + prompt->i) + 1);
		prompt->cmd[prompt->i] = *buff;
		prompt->i++;
		prompt_print(prompt, buff);
	}
}
