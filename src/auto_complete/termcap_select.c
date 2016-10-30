/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 21:11:14 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/30 15:02:40 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		clean_lst(t_struct *info)
{
	tputs(tgetstr("rc", NULL), 0, ft_putchar_int);
	tputs(tgetstr("cd", NULL), 0, ft_putchar_int);
	info->coeff = 0;
	info->len = 0;
	info->size_last = 0;
	info->count = info->node->length;
}

static char	*join_select(t_struct *info)
{
	t_lst	*ptr;
	char	*tmp;
	char	*str;

	ptr = info->node->head;
	str = NULL;
	tmp = NULL;
	while (ptr)
	{
		if (ptr->save)
		{
			tmp = ft_strdup("");
			str = ft_strjoin(tmp, ptr->save);
			free(tmp);
			tmp = ft_strjoin(str, " ");
			free(str);
		}
		ptr = ptr->next;
	}
	return (tmp);
}

static char	*deal_with_input(t_struct *info)
{
	char	*str;

	deal_with_arrow(info);
	start_end(info);
	if (*info->buff == 10)
	{
		info->on = 1;
		clean_lst(info);
		str = join_select(info);
		free_lst(info);
		return (str);
	}
	return (NULL);
}

void		print_lst(t_struct *info)
{
	t_lst	*ptr;

	ptr = info->node->head;
	clean_lst(info);
	while (ptr)
	{
		deal_with_col(info);
		print_opt(ptr, info);
		info->len++;
		if (info->len == info->node->length)
			info->realcol = info->coeff;
		ptr = ptr->next;
	}
}

char		*deal_with_term(t_struct *info)
{
	char	*str;

	if (read(0, info->buff, BUFF_SIZE) == -1)
		exit(-1);
	info->nb_item = (info->node->length) / info->nb_col;
	if (((info->node->length) % info->nb_col) != 0)
		info->nb_item += 1;
	str = deal_with_input(info);
	if (str)
		return (str);
	print_lst(info);
	ft_bzero(info->buff, BUFF_SIZE);
	return (NULL);
}
