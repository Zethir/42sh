/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:36:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/17 19:44:35 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void	prompt_hub(t_hub *info, char *buff)
{
	deal_with_charac(info, buff);
	deal_with_space(info, buff);
	deal_with_backspace(info, buff);
	deal_with_delete(info, buff);
	deal_with_left(info, buff);
	deal_with_right(info, buff);
	deal_with_up(info, buff);
	deal_with_down(info, buff);
	go_to_start_of_line(info, buff);
	go_to_previous_word(info, buff);
	go_to_next_word(info, buff);
	go_to_end(info, buff);
	start_copy_mode(info, buff);
	copy_string(info, buff);
	paste_string(info, buff);
	cut_string(info, buff);
}

char		*deal_with_termcap(t_hub *info)
{
	int			ret;
	char		buff[4];

	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	while ((ret = read(0, buff, BUFF_SIZE) != -1))
	{
		prompt_hub(info, buff);
		if (buff[0] == 10 && info->node->str)
		{
			if (info->node->next)
				go_to_end_list(info);
			break ;
		}
		ft_bzero(buff, 4);
	}
	return (info->node->str);
}
