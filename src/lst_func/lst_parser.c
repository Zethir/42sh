/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:01:38 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/30 16:02:58 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

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

static void deal_with_path(t_parse *parse, char **path)
{
	int     i;
	int     j;

	i = 0;
	j = 0;
	lex->parse->right_path = (char **)malloc(sizeof(char *) * list_browser(lex));
	if (!lex->parse->right_path)
		return ;
	while (lex->cmd)
	{
		if (path && *lex->cmd->argv && lex->cmd->env)
		{
			lex->parse->right_path[i] = check_path(path, *lex->cmd->argv);
			if (lex->parse->right_path[i])
			{
				lex->parse->right_path[i] = ft_strjoin(lex->parse->right_path[i], "/");
				lex->parse->bin_path = ft_strjoin(lex->parse->right_path[i], *lex->cmd->argv);
			}
			else
				lex->parse->right_path[i] = ft_strdup("");
		}
		else if (*lex->cmd->argv && lex->parse->env)
			lex->parse->right_path[i] = ft_strdup("");
		j++;
		i++;
		lex->cmd = lex->cmd->next;
	}
}

int         init_parse(t_lex *lex, t_env_hist *env_hist)
{
	char        **path;

	lex->parse->env = get_env(env_hist->lst);
	if (!(path = (char **)malloc(sizeof(char *) * 7)))
		return (-1);
	path = split_path(env_hist->lst);
	deal_with_path(lex, path);
	return (-1);

