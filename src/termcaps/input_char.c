/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:28:53 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/17 12:42:41 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	deal_with_delete(t_prompt *prompt, char *buff)
{
	if (DELETE && prompt->cmd[prompt->i])
	{
		ft_memmove(prompt->cmd + prompt->i, prompt->cmd + prompt->i + 1,
				ft_strlen(prompt->cmd + prompt->i + 1) + 1);
		prompt_print(prompt, 1);
	}
}

void	deal_with_backspace(t_prompt *prompt, char *buff)
{
	if (BACK_SPACE && prompt->i > 0)
	{
		prompt->i--;
		ft_memmove(prompt->cmd + prompt->i, prompt->cmd + prompt->i + 1,
				ft_strlen(prompt->cmd + prompt->i + 1) + 1);
		prompt_print(prompt, 1);
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
		prompt_print(prompt, 1);
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
		prompt_print(prompt, 1);
	}
}

void	input_clear(t_shell *sh, t_prompt *prompt, char *buff)
{
	char	*cmd;
	char	**env_cpy;

	if (buff[0] == 12)
	{
		cmd = ft_strdup("clear");
		env_cpy = get_env(sh->env);
		exec_env(sh, cmd, env_cpy);
		ft_free_tab(env_cpy);
		free(cmd);
		get_prompt(sh->env);
		prompt_print(prompt, 1);
	}
}
