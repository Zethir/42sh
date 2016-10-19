/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:28:53 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/19 16:25:39 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void		deal_with_delete(t_hub *info, char *buff)
{
	t_prompt 	*prompt;

	prompt = info->prompt;
	if (DELETE && prompt->cmd[prompt->i])
	{
		ft_memmove(prompt->cmd + prompt->i, prompt->cmd + prompt->i + 1,
				ft_strlen(prompt->cmd + prompt->i + 1) + 1);
		prompt_print(info, buff);
	}
	info->prompt = prompt;
}

void	deal_with_backspace(t_hub *info, char *buff)
{
	t_prompt 	*prompt;

	prompt = info->prompt;
	if (BACK_SPACE && prompt->i > 0)
	{
		prompt->i--;
		ft_memmove(prompt->cmd + prompt->i, prompt->cmd + prompt->i + 1,
				ft_strlen(prompt->cmd + prompt->i + 1) + 1);
		prompt_print(info, buff);
	}
	info->prompt = prompt;
}

void	deal_with_space(t_hub *info, char *buff)
{
	t_prompt 	*prompt;

	prompt = info->prompt;
	if (WHITE_SPACE)
	{
		ft_memmove(prompt->cmd + prompt->i + 1, prompt->cmd + prompt->i,
			ft_strlen(prompt->cmd + prompt->i) + 1);
		prompt->cmd[prompt->i] = ' ';
		prompt->i++;
		prompt_print(info, buff);
	}
	info->prompt = prompt;
}

void		deal_with_charac(t_hub *info, char *buff)
{
	t_prompt 	*prompt;

	prompt = info->prompt;
	if (CHARACTERE)
	{
		ft_memmove(prompt->cmd + prompt->i + 1, prompt->cmd + prompt->i,
				ft_strlen(prompt->cmd + prompt->i) + 1);
		prompt->cmd[prompt->i] = *buff;
		prompt->i++;
		prompt_print(info, buff);
	}
	info->prompt = prompt;
}
