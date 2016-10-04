/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:01:38 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/04 16:03:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static char        *check_path(char **path, char *arg)
{
	DIR             *dir;
	struct dirent   *ret;

	while (*path)
	{
		if ((dir = opendir(*path)))
		{
			while ((ret = readdir(dir)))
			{
				if (ft_strcmp(ret->d_name, arg) == 0)
				{
					closedir(dir);
					return (*path);
				}
			}
			closedir(dir);
		}
		path++;
	}
	return (NULL);
}

static char        **get_env(t_lst *node)
{
	t_lst   *tmp;
	char    **env;
	int     i;

	tmp = node;
	i = get_index(node);
	env = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (node)
	{
		if (node->line)
		{
			env[i] = ft_strdup(node->line);
			i++;
			node = node->next;
		}
		else
			node = node->next;
	}
	env[i] = NULL;
	node = tmp;
	return (env);
}

static char        **split_path(t_lst *node)
{
	t_lst           *tmp;
	char            **path;

	tmp = node;
	while (node)
	{
		if (ft_strcmp(node->name, "PATH") == 0)
		{
			if (node->line)
				path = ft_strsplit(&node->line[5], ':');
			else
				return (NULL);
		}
		node = node->next;
	}
	node = tmp;
	return (path);
}

static void deal_with_path(t_hub *info, char **path)
{
	t_lex	*lex;

	lex = info->lex;
	if (path && *info->parse->argv && info->parse->env)
	{
		info->parse->right_path = check_path(path, *info->parse->argv);
		if (info->parse->right_path)
		{
			info->parse->right_path = ft_strjoin(info->parse->right_path, "/");
			info->parse->right_path = ft_strjoin(info->parse->right_path, *info->parse->argv);
		}
		else
			info->parse->right_path = ft_strdup("");
	}
	else if (*info->parse->argv && info->parse->env)
		info->parse->right_path = ft_strdup("");
}

int         init_parse(t_hub *info)
{
	char        **path;

	info->parse = (t_parse *)malloc(sizeof(t_parse));
	info->parse->env = get_env(info->lst);
	info->parse->argv = ft_strsplit_ws(info->lex->token->name);
	if (!(path = (char **)malloc(sizeof(char *) * 7)))
		return (-1);
	path = split_path(info->lst);
	deal_with_path(info, path);
	return (-1);
}
