/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 11:47:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 19:19:33 by cboussau         ###   ########.fr       */
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
	t_lex	*lex;

	lex = init_lexer_struct();
	lex->line = ft_strdup(deal_with_termcap(sh));
	deal_with_inhib(sh, lex);
	ft_putchar('\n');
	if (!lex->line)
		return ;
	lex->token = init_token_struct();
	if (check_lexer(sh, lex) == -1)
		return ;
	init_stdio(sh);
	parse_cmd(sh, lex->token);
	add_history(sh);
	free_lex(&lex);
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
		push_node_bis(&sh->hist, create_node());
		sh->hist = sh->hist->next;
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
