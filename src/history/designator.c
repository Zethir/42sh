/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:55:39 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/04 15:41:44 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void	exec_cmd_add_lst(t_hub *info, char *line)
{
	char	**tabl;
	int		i;

	i = 0;
	tabl = ft_strsplit_ws(line);
	info->node->str = ft_strdup("");
	while (tabl[i])
	{
		ft_putstr(tabl[i]);
		if (i != 0)
			info->node->str = ft_strjoin(info->node->str, " ");
		info->node->str = ft_strjoin(info->node->str, tabl[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	info->parse->argv[0] = ft_strdup(info->node->str);
	init_parse(info);
	exec_cmd(info);
}

static void	deal_with_dash(t_hub *info, char **cmd, int fd)
{
	int		i;
	t_dlist	*dlist;
	char	*line;

	dlist = info->node;
	i = 0;
	while (info->node->prev)
	{
		info->node = info->node->prev;
		i++;
	}
	info->node = dlist;
	i = i - ft_atoi(&cmd[0][2]);
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
		{
			while (*line != ' ')
				line++;
			exec_cmd_add_lst(info, line);
		}
		i--;
	}
}

static void	deal_with_number(t_hub *info, char **cmd, int fd)
{
	char	*line;
	int		i;

	i = ft_atoi(&cmd[0][1]);
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
		{
			while (*line != ' ')
				line++;
			exec_cmd_add_lst(info, line);
		}
		i--;
	}
}

static void	deal_with_string(t_hub *info, char **cmd)
{
	t_dlist	*dlist;
	char	*line;

	dlist = info->node;
	while (info->node->prev)
	{
		if (ft_strncmp(info->node->str, &cmd[0][1], ft_strlen(&cmd[0][1])) == 0)
		{
			line = ft_strdup(info->node->str);
			info->node = dlist;
			exec_cmd_add_lst(info, line);
			break ;
		}
		info->node = info->node->prev;
	}
	info->node = dlist;
}

void	do_designator(t_hub *info, char **cmd)
{
	int		fd;
	char	*str;

	str = get_home(info->lst);
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("history");
		exit(-1);
	}
	if (cmd[0][1] == '-')
	{
		if (check_number_bis(cmd) == 0)
			deal_with_dash(info, cmd, fd);
	}
	else if (cmd[0][1] >= '0' && cmd[0][1] <= '9')
	{
		if (check_number(cmd) == 0)
			deal_with_number(info, cmd, fd);
	}
	else
	{
		if (check_alpha(cmd) == 0)
			deal_with_string(info, cmd);
	}
	close(fd);
}
