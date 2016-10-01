/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 11:47:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/01 16:36:17 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static void		deal_with_prompt(t_hub *info)
{
	info->lex = init_lexer_struct();
	info->lex->line = deal_with_termcap(info);
	ft_putchar('\n');
	if (!info->lex->line)
		return ;
	info->lex->arg = ft_strsplit(info->lex->line, ';');
	while (*info->lex->arg)
	{
		info->lex->cmd = init_cmd_struct();
		info->lex->token = init_token_struct();
		check_lexer(info->lex);
		init_parse(info);
		parse_cmd(info);
		free_struct_lex(info->lex);
		free_parse(info->parse);
		info->lex->arg++;
	}
	free_lex(info->lex);
	add_history(info);
}

static void		start_prog(char **env)
{
	t_hub	*info;

	info = init_struct(env);
	while (1)
	{
		if (check_lst(info->lst) == 0)
			info->lst = init_lst(env);
		get_prompt(info->lst);
		stock_struct(info, 0);
		deal_with_prompt(info);
		push_node_bis(&info->node, create_node());
		info->node = info->node->next;
	}
	if (reset_term(info) == -1)
		return ;
	if (info->lst)
		free_list(info->lst);
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
