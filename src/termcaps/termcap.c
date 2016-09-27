/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:36:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/27 17:14:25 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

static void	deal_with_backspace(t_env_hist *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (BACK_SPACE && node->i > 0)
	{
		node->i--;
		ft_memmove(node->str + node->i, node->str + node->i + 1,
				ft_strlen(node->str + node->i + 1) + 1);
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
		tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

static void	deal_with_space(t_env_hist *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (WHITE_SPACE)
	{
		ft_memmove(node->str + node->i + 1, node->str + node->i,
				ft_strlen(node->str + node->i) + 1);
		node->str[node->i] = ' ';
		node->i++;
		tputs(tgetstr("im", NULL), 1, ft_putchar_int);
		ft_putchar(' ');
		tputs(tgetstr("ei", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

static void	deal_with_arrow(t_env_hist *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (ARROW_LEFT && node->i > 0)
	{
		node->i--;
		tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	}
	if (ARROW_RIGHT && node->str[node->i])
	{
		node->i++;
		tputs(tgetstr("nd", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

static void	deal_with_charac(t_env_hist *info, char *buff)
{
	t_dlist		*node;

	node = info->node;
	if (CHARACTERE)
	{
		ft_memmove(node->str + node->i + 1, node->str + node->i,
				ft_strlen(node->str + node->i) + 1);
		node->str[node->i] = *buff;
		node->i++;
		tputs(tgetstr("im", NULL), 1, ft_putchar_int);
		write(1, &buff[0], 1);
		tputs(tgetstr("ei", NULL), 1, ft_putchar_int);
	}
	info->node = node;
}

char		*deal_with_termcap(t_env_hist *info)
{
	int			ret;
	char		buff[4];

	tputs(tgetstr("sc", NULL), 1, ft_putchar_int);
	while ((ret = read(0, buff, BUFF_SIZE) != -1))
	{
		deal_with_charac(info, buff);
		deal_with_others(info, buff);
		deal_with_space(info, buff);
		deal_with_backspace(info, buff);
		deal_with_arrow(info, buff);
		go_to_end(info, buff);
		if (buff[0] == 10 && info->node->str)
		{
			if (info->node->next)
				go_to_end_list(info);
			break ;
		}
	}
	return (info->node->str);
}
