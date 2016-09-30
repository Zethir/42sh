/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:55:13 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 17:12:31 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void		print_env(t_lst *node)
{
	t_lst *tmp;

	tmp = node;
	while (node)
	{
		if (!node->line)
			node = node->next;
		else if (node->flag == 0)
			ft_putendl(node->line);
		node = node->next;
	}
	node = tmp;
}

static char	*cmp_line(t_lex *lex, char **arg, char *save)
{
	t_lst	*tmp;

	tmp = lex->info->lst;
	while (lex->info->lst)
	{
		if (ft_strccmp(lex->info->lst->line, *arg, '=') == 0)
		{
			save = ft_strdup(lex->info->lst->line);
			lex->info->lst->line = ft_strdup(*arg);
			return (save);
		}
		lex->info->lst = lex->info->lst->next;
	}
	lex->info->lst = tmp;
	save = NULL;
	if (!save)
	{
		if (check_caract(*arg, '=') == 1)
			add_elem(lex->info->lst, *arg);
		else if (check_caract(*arg, '=') != 1)
			exec_cmd(lex);
		else
			print_error_opt(*arg);
	}
	return (save);
}

static char	**deal_with_arg(t_lex *lex, char **arg)
{
	char	**save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	save = malloc_tab(arg);
	while (*arg)
	{
		save[i] = cmp_line(lex, arg, save[i]);
		if (!save[i] && *arg && check_caract(*arg, '=') == 1)
			save[i] = ft_strdup("");
		if ((!save[i] || ft_strlen(save[i]) == 0)
				&& *arg && check_caract(*arg, '=') == 1)
			j++;
		i++;
		arg++;
	}
	if (j > 0 || save[0])
		print_env(lex->info->lst);
	while (j-- > 0)
		lex->info->lst = delete_elem(lex->info->lst);
	return (save);
}

void		restore_env(t_lst *node, char **save)
{
	t_lst	*tmp;

	tmp = node;
	while (*save && *save[0])
	{
		while (node)
		{
			if (ft_strncmp(node->name, *save, ft_strlen(node->name)) == 0)
				node->line = ft_strdup(*save);
			node = node->next;
		}
		node = tmp;
		save++;
	}
}

int			deal_with_env(t_lex *lex, char **arg)
{
	char	**save;

	arg++;
	if (*arg)
	{
		if (*arg[0] == '-')
			save = deal_with_opt(lex, arg);
		else
			save = deal_with_arg(lex, arg);
		if (!save || !*save)
			return (-1);
		restore_env(lex->info->lst, save);
		free(save);
	}
	else
		print_env(lex->info->lst);
	return (-1);
}
