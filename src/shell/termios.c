/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:32:18 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 17:08:41 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int			reset_term(t_hub *info)
{
	if (tcgetattr(0, &(info->term)) == -1)
		return (-1);
	info->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(info->term)) == -1)
		return (-1);
	return (0);
}

int			init_term(t_hub *info)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) != 1)
		return (-1);
	if (tcgetattr(0, &(info->term)) == -1)
		return (-1);
	info->term.c_lflag &= ~(ICANON | ECHO);
	info->term.c_cc[VMIN] = 1;
	info->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(info->term)) == -1)
		return (-1);
	return (0);
}

t_hub	*stock_struct(t_hub *info, int i)
{
	static t_hub *tmp = NULL;

	if (i == 0)
		tmp = info;
	return (tmp);
}

t_hub	*init_struct(char **env)
{
	t_hub	*info;

	if (!(info = (t_hub *)malloc(sizeof(t_hub))))
		return (NULL);
	info->lst = init_lst(env);
	if (!(info->node = (t_dlist *)malloc(sizeof(t_dlist))))
		return (NULL);
	info->node = create_node();
	info->lex = init_lexer_struct();
	deal_with_file(info);
	if (init_term(info) == -1)
		return (NULL);
	return (info);
}
