/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:45:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/01 15:51:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

char	*input_return(t_shell *sh, t_prompt *prompt)
{
	char	*str;

	str = NULL;
	prompt_print(prompt, 0);
	while (sh->hist->next)
		sh->hist = sh->hist->next;
	if (prompt->cmd[0])
	{
		sh->hist->str = ft_strdup(prompt->cmd);
		str = ft_strdup(sh->hist->str);
		return (str);
	}
	else
		sh->hist->str = ft_strdup("");
	return (str);
}
