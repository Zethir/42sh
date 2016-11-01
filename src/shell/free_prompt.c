/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:29:44 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/30 19:32:18 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	free_prompt(t_prompt **prompt)
{
	t_prompt *tmp;

	tmp = *prompt;
	tmp->i = 0;
	tmp->copy_mode = 0;
	tmp->cursor_start = 0;
	tmp->cursor_end = 0;
	if (tmp->copy_str)
		free(tmp->copy_str);
	tmp->win_size = 0;
	free(tmp);
	tmp = NULL;
}
