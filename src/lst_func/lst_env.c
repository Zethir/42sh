/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:37:50 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/13 16:00:29 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int			check_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (env->line)
			return (1);
		else
			env = env->next;
	}
	env = tmp;
	return (0);
}

int			get_intel(t_env *env, char *str)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, str) == 0)
		{
			env = tmp;
			return (1);
		}
		env = env->next;
	}
	env = tmp;
	return (0);
}

void		push_node(t_env *env, t_env **head)
{
	t_env	*tmp;

	if (*head == NULL)
	{
		*head = env;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = env;
}

static void	shell_level(char **env)
{
	char	**tabl;
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	i = ft_atoi(ft_strchr(*env, '=') + 1);
	i += 1;
	tabl = ft_strsplit(*env, '=');
	if (tabl[1])
		free(tabl[1]);
	tabl[1] = ft_itoa(i);
	str = ft_strjoin(tabl[0], "=");
	tmp = ft_strjoin(str, tabl[1]);
	free(str);
	ft_bzero(*env, ft_strlen(*env));
	ft_strcpy(*env, tmp);
	free(tmp);
	ft_free_tab(tabl);
}

t_env		*init_env(char **env)
{
	t_env	*node;
	t_env	*head;

	head = NULL;
	while (*env)
	{
		if (!(node = (t_env *)malloc(sizeof(t_env))))
			return (NULL);
		node->next = NULL;
		if (ft_strncmp(*env, "SHLVL", 5) == 0)
			shell_level(&*env);
		if (*env[0])
			node->line = ft_strdup(*env);
		node->flag = 0;
		node->name = ft_strsub(*env, 0, ft_strlen_char(*env, '='));
		push_node(node, &head);
		env++;
	}
	return (head);
}
