/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 13:38:49 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/01 14:05:15 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static char		*check_path(char **path, char *arg)
{
	DIR				*dir;
	struct dirent	*ret;

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

char			**get_env(t_env *node)
{
	t_env	*tmp;
	char	**env;
	int		i;

	i = get_index(node);
	env = (char **)malloc(sizeof(char *) * i + 1);
	tmp = node;
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

static char		**split_path(t_env *env)
{
	t_env	*tmp;
	char	**path;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
		{
			if (env->line)
			{
				path = ft_strsplit(&env->line[5], ':');
				return (path);
			}
			else
				return (NULL);
		}
		env = env->next;
	}
	env = tmp;
	return (NULL);
}

static void		deal_with_path(t_parse *parse, char **path)
{
	char	*tmp;

	if (path && *parse->argv && parse->env)
	{
		parse->right_path = check_path(path, *parse->argv);
		if (parse->right_path)
		{
			tmp = ft_strjoin(parse->right_path, "/");
			parse->right_path = ft_strjoin(tmp, *parse->argv);
			free(tmp);
		}
		else
		{
			tmp = ft_strdup("");
			parse->right_path = ft_strjoin(tmp, *parse->argv);
			free(tmp);
		}
	}
	else if (*parse->argv && parse->env)
	{
		tmp = ft_strdup("");
		parse->right_path = ft_strjoin(tmp, *parse->argv);
		free(tmp);
	}
}

t_parse			*init_parse(t_shell *sh, char *cmd)
{
	t_parse	*parse;
	char	**path;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->env = get_env(sh->env);
	parse->argv = ft_strsplit_ws(cmd);
	path = split_path(sh->env);
	deal_with_path(parse, path);
	ft_free_tab(path);
	return (parse);
}
