/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:21:49 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 18:39:51 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/*void	exec_pipe(t_lex *lex)
{
	int		pipefd[2];

	pipe(pipefd);
	if (check_builtins(lex))
	{
		if (lex->cmd->next && lex->parse->bl == 0)
			dup2(pipefd[1], 1);
		if (lex->parse->bl != 0)
			dup2(pipefd[0], 0);
		do_builtins(lex);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	else if ((lex->parse->pid = fork()) == 0)
	{
		if (lex->cmd->next && lex->parse->bl == 0)
			dup2(pipefd[1], 1);
		if (lex->parse->bl != 0)
			dup2(pipefd[0], 0);
		close(pipefd[0]);
		close(pipefd[1]);
		if (execve(str, lex->cmd->argv, lex->parse->env) < 0)
		{
			no_command_error(lex->cmd->argv[0]);
			exit (-1);
		}
	}
	else if (lex->parse->pid < 0)
		exit (-1);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(0);
	if (lex->parse->bl == 1)
		lex->parse->bl = 0;
	else
		lex->parse->bl = 1;
	lex->token = lex->token->next;
	if (lex->token == 3)
		exec_pipe(lex);
	else
		parse_cmd(lex);
}*/
