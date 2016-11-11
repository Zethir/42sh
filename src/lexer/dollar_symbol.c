/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:25:30 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/11 17:51:09 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static void	change_value(t_lex *lex, char *data, int *i, int crop)
{
	char	cpy1[(*i) + 1];
	char	cpy2[lex->lencmd + 1];
	char	*tmp;

	ft_bzero(cpy1, (*i) + 1);
	ft_bzero(cpy2, lex->lencmd + 1);
	ft_strncpy(cpy1, lex->token->cmd, (*i));
	ft_strcpy(cpy2, lex->token->cmd + (*i) + crop);
	free(lex->token->cmd);
	tmp = ft_strjoin(cpy1, data);
	lex->token->cmd = ft_strjoin(tmp, cpy2);
	free(tmp);
}

static int	check_env_data(t_shell *sh, t_lex *lex, char *data, int *i)
{
	t_env	*env;
	char	*val;

	env = sh->env;
	while (env)
	{
		if (!ft_strcmp(env->name, data))
		{
			val = ft_strsub(env->line, 5, ft_strlen(env->line) - 5);
			lex->lencmd = ft_strlen(lex->token->cmd) - (*i) -
				ft_strlen(data) - 1;
			change_value(lex, val, i, ft_strlen(data) + 1);
			(*i) = (*i) + ft_strlen(val) - 1;
			free(val);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

static void	check_for_var(t_shell *sh, t_lex *lex, int *i)
{
	char	str[100];
	int		ref;
	int		j;

	j = 0;
	ref = (*i) + 1;
	ft_bzero(str, 100);
	while (lex->token->cmd[ref] && !ft_isspace(lex->token->cmd[ref]) &&
			j < 100 && lex->token->cmd[ref] != '$')
	{
		str[j] = lex->token->cmd[ref];
		j++;
		ref++;
	}
	if (check_env_data(sh, lex, str, i) == 0)
	{
		lex->lencmd = ft_strlen(lex->token->cmd) - (*i) - ft_strlen(str) - 1;
		change_value(lex, "", i, ft_strlen(str) + 1);
		(*i) = (*i) - 1;
	}
}

static void	change_value_dollar(t_shell *sh, t_lex *lex, int *i)
{
	char	*ret;

	ret = NULL;
	lex->lencmd = 0;
	if (lex->token->cmd[(*i) + 1] == '?')
	{
		ret = ft_itoa(sh->return_val);
		lex->lencmd = ft_strlen(lex->token->cmd) - (*i) - 2;
		change_value(lex, ret, i, 2);
		(*i) = (*i) + ft_strlen(ret) - 1;
		free(ret);
	}
	else if (lex->token->cmd[(*i) + 1] == '$')
	{
		ret = ft_itoa(getpid());
		lex->lencmd = ft_strlen(lex->token->cmd) - (*i) - 2;
		change_value(lex, ret, i, 2);
		(*i) = (*i) + ft_strlen(ret) - 1;
		free(ret);
	}
	else if (lex->token->cmd[(*i) + 1])
		check_for_var(sh, lex, i);
}

void		dollar_symbol(t_shell *sh, t_lex *lex)
{
	t_token		*tmp;
	int			i;

	tmp = lex->token;
	i = 0;
	while (lex->token)
	{
		while (lex->token->cmd[i])
		{
			if (lex->token->cmd[i] == '$')
				change_value_dollar(sh, lex, &i);
			i++;
		}
		i = 0;
		lex->token = lex->token->next;
	}
	lex->token = tmp;
}
