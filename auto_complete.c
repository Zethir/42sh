/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:33:03 by qdiaz             #+#    #+#             */
/*   Updated: 2016/07/26 20:51:10 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int		check(char *str)
{
	if ((str[0] >= 'A' && str[0] <= 'Z') ||
			(str[0] >= 'a' && str[0] <= 'z') ||
			(str[0] >= '0' && str[0] <= '9') ||
			str[0] == '.')
		return (1);
	else
		return (0);
}

static void		tab_to_select(char **file_tab, char *str)
{
	char        	**sel;
	int				i;
	int				j;
	char			**cmd;
	pid_t			pid;

	i = 0;
	j = 1;
	cmd = ft_strsplit_ws(str);
	pid = fork();
	sel = (char **)malloc(sizeof(char *));
	sel[0] = ft_strdup("ft_select");
	while (file_tab[i])
	{
		if (!ft_strncmp(cmd[1], file_tab[i], ft_strlen(cmd[1])))
		{
			sel[j] = file_tab[i];
			j++;
		}
		i++;
	}
	sel[j] = NULL;
	ft_putchar('\n');
	exec_select(j, sel);
	exit(0);
}

void		tab_completion(char *str)
{
	char			*file_names;
	char			**file_tab;
	DIR				*dir;
	struct dirent	*ret;

	if (!check(str))
		return ;
	dir = opendir(".");
	while ((ret = readdir(dir)))
	{
		file_names = ft_strjoin(file_names, " "); 
		file_names = ft_strjoin(file_names, ret->d_name); 
	}
	closedir(dir);
	file_tab = ft_strsplit(file_names, ' ');
	tab_to_select(file_tab, str);
}
