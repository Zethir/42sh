/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:37:50 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 15:37:55 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		check_env(t_env *env)
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

int		get_intel(t_env *env, char *str)
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

void	push_node(t_env *env, t_env **head)
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

t_env	*init_env(char **env)
{
	t_env	*node;
	t_env	*head;

	head = NULL;
	while (*env)
	{
		if (!(node = (t_env *)malloc(sizeof(t_env))))
			return (NULL);
		node->next = NULL;
		node->line = ft_strdup(*env);
		node->flag = 0;
		node->name = ft_strsub(*env, 0, ft_strlen_char(*env, '='));
		if (ft_strccmp(*env, "USER=", '=') == 0)
			node->user = ft_strsub(*env, 5, ft_strlen(*env) - 5);
		else
			node->user = NULL;
		if (ft_strncmp(*env, "HOME=", 5) == 0)
			node->home = ft_strdup(ft_strchr(*env, '/'));
		else
			node->home = NULL;
		push_node(node, &head);
		env++;
	}
	return (head);
}
