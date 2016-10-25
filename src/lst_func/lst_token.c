/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/25 20:37:05 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static void		push_token(t_token *node, t_token **head)
{
	t_token		*tmp;
	t_token		*tmp2;

	tmp2 = *head;
	if (tmp2->cmd == NULL)
	{
		*head = node;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

static char		*clean_cmd(char *cmd)
{
	char	**str;
	char	*res;
	char	*tmp;
	int		i;

	str = ft_strsplit_ws(cmd);
	if (!str[0])
		return (NULL);
	res = ft_strdup(str[0]);
	i = 1;
	while (str[i])
	{
		tmp = ft_strjoin(res, " ");
		free(res);
		res = ft_strjoin(tmp, str[i]);
		free(tmp);
		i++;
	}
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (res);
}

int				add_token(t_lex *lex, char *cmd, int val)
{
	t_token		*new_elem;

	if (!(new_elem = (t_token *)malloc(sizeof(t_token))))
		return (-1);
	if (!(new_elem->fd = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	new_elem->next = NULL;
	cmd = clean_cmd(cmd);
	if (!cmd)
		return (-1);
	new_elem->cmd = ft_strdup(cmd);
	new_elem->token_value = val;
	new_elem->fd[0] = lex->fd[0];
	new_elem->fd[1] = lex->fd[1];
	push_token(new_elem, &lex->token);
	free(cmd);
	return (0);
}

t_token			*init_token_struct(void)
{
	t_token *token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	token->next = NULL;
	token->cmd = NULL;
	token->token_value = 0;
	token->fd = NULL;
	return (token);
}
