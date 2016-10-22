/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:36:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 11:30:05 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void	reset_prompt(t_hub *info)
{
	size_t	i;
	size_t	j;

	j = 3;
	i = 0;
	tputs(tgetstr("vi", NULL), 1, ft_putchar_int);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	while (i < ft_strlen(info->prompt->cmd))
	{
		if (j >= info->prompt->win_size)
		{
			tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
			tputs(tgetstr("up", NULL), 1, ft_putchar_int);
			j = 0;
		}
		j++;
		i++;
	}
	tputs(tgetstr("cd", NULL), 1, ft_putchar_int);
	color(RED, "$> ");
	color(RESET, "");
}

void		prompt_print(t_hub *info, char *buff)
{
	int		i;
	size_t	j;

	i = 0;
	reset_prompt(info);
	j = 3;
	while (info->prompt->cmd[i])
	{
		tputs(tgetstr("me", NULL), 1, ft_putchar_int);
		if (i == info->prompt->i)
			tputs(tgetstr("mr", NULL), 1, ft_putchar_int);
		if (info->prompt->copy_mode == 1 && i >= info->prompt->cursor_start &&
				i <= info->prompt->cursor_end)
			tputs(tgetstr("mr", NULL), 1, ft_putchar_int);
		ft_putchar(info->prompt->cmd[i]);
		j++;
		if (j >= info->prompt->win_size)
		{
			ft_putendl("");
			tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
			j = 0;
		}
		i++;
	}
	if (i == info->prompt->i && buff[0] != 10)
	{
		tputs(tgetstr("mr", NULL), 1, ft_putchar_int);
		ft_putchar(' ');
	}
	tputs(tgetstr("me", NULL), 1, ft_putchar_int);
}

static void	prompt_hub(t_hub *info, char *buff)
{
	if (ft_strlen(info->prompt->cmd) <= 10000)
	{
		deal_with_charac(info, buff);
		deal_with_space(info, buff);
	}
	go_down_line(info, buff);
	go_up_line(info, buff);
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
	cut_string(info, buff);
	paste_string(info, buff);
}

char		*deal_with_termcap(t_hub *info)
{
	int			ret;
	char		buff[4];

	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	info->prompt = init_prompt();
	prompt_print(info, buff);
	while ((ret = read(0, buff, BUFF_SIZE) != -1))
	{
		prompt_hub(info, buff);
		if (buff[0] == 10 && info->prompt->cmd)
		{
			prompt_print(info, buff);
			if (info->node->next)
				go_to_end_list(info);
			if (info->prompt->cmd[0])
				info->node->str = info->prompt->cmd;
			else
				return (NULL);
			break ;
		}
		ft_bzero(buff, 4);
	}
	return (info->prompt->cmd);
}
