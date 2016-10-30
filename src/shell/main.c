/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 11:47:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/30 19:32:59 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static void		deal_with_inhib(t_shell *sh, t_lex *lex)
{
	char	*tmp;

	tmp = ft_strdup("");
	if (!lex->line)
		return ;
	while (check_for_parenth(lex->line) != 0)
	{
		ft_putchar('\n');
		tmp = deal_with_termcap(sh);
		lex->line = ft_strjoin(lex->line, tmp);
	}
	free(tmp);
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
	if ((lex->token = check_lexer(lex, token_ht, sh)) == NULL)
		return ;
	init_stdio(sh);
	parse_cmd(sh, lex->token);
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
		get_prompt(sh->env);
		stock_struct(sh, 0);
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

	argv = NULL;
	id = 0;
	signal(SIGINT, SIG_IGN);
	ft_signal(id);
	if (argc == 1)
		start_prog(env);
	else
		return (1);
	return (0);
}
