/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:27:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/02 16:34:48 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static char		*clean_cmd(char *cmd)
{
	char	**str;
	char	*res;
	char	*tmp;
	int		i;

	str = ft_strsplit_ws(cmd);
	if (!str[0])
	{
		ft_free_tab(str);
		return (NULL);
	}
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
	ft_free_tab(str);
	return (res);
}

t_token			*cmd_is_empty(t_lex *lex, t_token *new_elem, int val)
{
	new_elem->cmd = ft_strdup("");
	new_elem->token_value = val;
	new_elem->fd[0] = lex->fd[0];
	new_elem->fd[1] = lex->fd[1];
	return (new_elem);
}

t_token			*init_token(t_lex *lex, t_token_ht *token, char *cmd, int val)
{
	t_token		*new_elem;
	int			value;

	if (!(new_elem = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	if (token->tail)
		value = token->tail->token_value;
	else
		value = 0;
	cmd = clean_cmd(cmd);
	if (!cmd && (value == 7 || value == 8 || value == 11 || value == 12))
		return (cmd_is_empty(lex, new_elem, val));
	else if (!cmd)
	{
		free(new_elem);
		return (NULL);
	}
	new_elem->cmd = ft_strdup(cmd);
	new_elem->token_value = val;
	new_elem->fd[0] = lex->fd[0];
	new_elem->fd[1] = lex->fd[1];
	free(cmd);
	return (new_elem);
}

t_token_ht		*add_token(t_lex *lex, t_token_ht *token_ht, char *cmd, int val)
{
	t_token		*token;

	if (token_ht)
	{
		token = init_token(lex, token_ht, cmd, val);
		if (!token)
			return (NULL);
		if (token_ht->tail == NULL)
		{
			token->prev = NULL;
			token_ht->head = token;
			token_ht->tail = token;
		}
		else
		{
			token_ht->tail->next = token;
			token->prev = token_ht->tail;
			token_ht->tail = token;
		}
	}
	return (token_ht);
}
