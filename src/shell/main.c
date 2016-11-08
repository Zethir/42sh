/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 11:47:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/08 16:29:02 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static void		deal_with_inhib(t_shell *sh, t_lex *lex)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	while (check_for_quotes(lex->line) != 0)
	{
		tmp = termcap_heredoc(sh);
		tmp2 = ft_strjoin("\n", tmp);
		free(tmp);
		tmp = ft_strjoin(lex->line, tmp2);
		free(lex->line);
		free(tmp2);
		lex->line = ft_strdup(tmp);
		free(tmp);
		free(sh->hist->str);
		sh->hist->str = ft_strdup(lex->line);
		ft_putchar('\n');
	}
}

static int		lexer_parser(t_shell *sh, t_lex *lex, t_token_ht *token_ht)
{
	if ((lex->token = check_lexer(lex, token_ht, sh)) == NULL)
	{
		free_lex(&lex);
		free_token_ht(&token_ht);
		return (-1);
	}
	init_stdio(sh);
	parse_cmd(sh, lex->token);
	return (0);
}

static void		deal_with_prompt(t_shell *sh)
{
	t_token_ht	*token_ht;
	t_lex		*lex;

	if (!(token_ht = (t_token_ht *)malloc(sizeof(t_lex))))
		return ;
	token_ht->head = NULL;
	token_ht->tail = NULL;
	lex = init_lexer_struct();
	lex->line = deal_with_termcap(sh);
	ft_putchar('\n');
	if (!lex->line)
	{
		free_lex(&lex);
		free_token_ht(&token_ht);
		return ;
	}
	deal_with_inhib(sh, lex);
	if (lexer_parser(sh, lex, token_ht) == -1)
		return ;
	add_history(sh);
	free_lex(&lex);
	free_token_ht(&token_ht);
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
