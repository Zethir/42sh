/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 11:47:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/17 12:24:40 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static void		deal_with_inhib(t_shell *sh, char **str)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	while (check_for_quotes(*str) != 0)
	{
		tmp = termcap_heredoc(sh);
		tmp2 = ft_strjoin("\n", tmp);
		free(tmp);
		tmp = ft_strjoin(*str, tmp2);
		free(*str);
		free(tmp2);
		*str = ft_strdup(tmp);
		free(tmp);
		free(sh->hist->str);
		sh->hist->str = ft_strdup(*str);
		ft_putchar('\n');
	}
}

static int		lexer_parser(t_shell *sh, char *cmd)
{
	t_token_ht	*token_ht;
	t_lex		*lex;

	token_ht = init_token_ht();
	lex = init_lexer_struct();
	lex->line = ft_strdup(cmd);
	if ((lex->token = check_lexer(lex, token_ht, sh)) == NULL)
	{
		free_lex(&lex);
		free_token_ht(&token_ht);
		return (-1);
	}
	dollar_symbol(sh, lex);
	init_stdio(sh);
	sh->return_val = 0;
	parse_cmd(sh, lex->token);
	free_lex(&lex);
	free_token_ht(&token_ht);
	return (0);
}

static void		deal_with_prompt(t_shell *sh)
{
	char		*str;
	char		**cmd;
	int			i;

	i = 0;
	str = deal_with_termcap(sh);
	ft_putchar('\n');
	if (!str)
		return ;
	deal_with_inhib(sh, &str);
	cmd = ft_strsplit(str, ';');
	free(str);
	while (cmd[i])
	{
		if (init_term(sh) == -1)
			return ;
		if (lexer_parser(sh, cmd[i]) == -1)
			return ;
		i++;
	}
	add_history(sh);
	ft_free_tab(cmd);
}

static void		start_prog(char **env)
{
	t_shell	*sh;

	sh = init_struct(env);
	while (1)
	{
		if (init_term(sh) == -1)
			return ;
		if (check_env(sh->env) == 0)
			sh->env = init_env(env);
		stock_struct(sh, 0);
		get_prompt(sh->env);
		deal_with_prompt(sh);
		sh->hist = sh->hist->next;
		sh->hist = create_hist();
		push_hist(&sh->head, sh->hist);
	}
	if (reset_term(sh) == -1)
		return ;
}

int				main(int argc, char **argv, char **env)
{
	int		id;

	id = 0;
	argv = NULL;
	ign_signal(id);
	if (argc == 1)
		start_prog(env);
	else
		return (1);
	return (0);
}
