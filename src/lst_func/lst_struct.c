/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:17:17 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 17:02:31 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

t_hub		*stock_struct(t_hub *info, int i)
{
	static t_hub *tmp = NULL;

	if (i == 0)
		tmp = info;
	return (tmp);
}

t_prompt	*init_prompt(void)
{
	t_prompt		*prompt;
	struct winsize	win;

	if (!(prompt = (t_prompt *)malloc(sizeof(t_prompt))))
		return (NULL);
	if (!(prompt->cmd = (char *)malloc(sizeof(char) * 10000)))
		return (NULL);
	ft_bzero(prompt->cmd, 10000);
	prompt->i = 0;
	prompt->copy_mode = 0;
	prompt->cursor_start = 0;
	prompt->cursor_end = 0;
	prompt->copy_str = ft_strdup("");
	ioctl(0, TIOCGWINSZ, &win);
	prompt->win_size = win.ws_col;
	return (prompt);
}

t_hub		*init_struct(char **env)
{
	t_hub	*info;

	if (!(info = (t_hub *)malloc(sizeof(t_hub))))
		return (NULL);
	info->lst = init_lst(env);
	if (!(info->node = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	info->node = create_node();
	deal_with_file(info);
	return (info);
}

void		init_stdio(t_hub *info)
{
	if (!(info->stdio = (int *)malloc(sizeof(int) * 3)))
		return ;
	info->stdio[0] = 0;
	info->stdio[1] = 1;
	info->stdio[2] = 2;
	info->closefd = -1;
}
