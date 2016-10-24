/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:20:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/24 16:17:46 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <lexer.h>
# include <shell.h>

typedef struct			s_parse
{
	char				**argv;
	char				*right_path;
	char				**env;
	pid_t				pid;
}						t_parse;

typedef struct			s_process
{
	char				*cmd;
	int					*stdio;
	char				aggr;
	int					closefd;
	int					completed;
	struct s_process	*next;

}						t_process;

typedef struct			s_job
{
	int					linker;
	struct s_process	*process;
	struct s_job		*next;
}						t_job;

t_job					*init_job(void);
t_parse					*init_parse(t_shell *sh, char *cmd);
void					exec_job(t_shell *sh, t_job *job);
void					push_process(t_process *node, t_process **head);
void					push_job(t_job *node, t_job **head);
void					wait_for_process(t_process *process);
void					free_job(t_job *job);
void					free_parse(t_parse **head);
void					launch_builtin(t_shell *sh, t_parse *pa, t_process *pr);
void					launch_bin(t_shell *sh, t_parse *p, t_process *process);
void					create_job(t_job *job, t_token *token);
void					exec_process(t_shell *sh, t_process *p, int *iofile);
void					create_process(t_job *job, t_token *token, t_shell *sh);
void					token_linker(t_shell *sh, t_job *job, t_token *token);
void					token_pipe(t_shell *sh, t_job *job, t_token *token);
int						do_builtins(t_shell *sh, t_parse *parse);

#endif
