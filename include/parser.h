/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:20:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/05 10:42:57 by cboussau         ###   ########.fr       */
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
	int					stdio[3];
	char				aggr;
	int					closefd;
	int					completed;
	pid_t				pid;
	struct s_process	*next;

}						t_process;

typedef struct			s_job
{
	int					linker;
	pid_t				pgid;
	struct s_process	*process;
	struct s_job		*next;
}						t_job;

t_job					*init_job(void);
t_parse					*init_parse(t_shell *sh, char *cmd);
void					exec_job(t_shell *sh, t_job *job);
void					exec_process(t_shell *sh, t_job *job, int *iofile);
void					push_process(t_process *node, t_process **head);
void					push_job(t_job *node, t_job **head);
void					wait_for_job(t_job *job, int i);
void					update_process_status(t_process *p, pid_t pid, int sta);
void					free_job(t_job *job);
void					free_parse(t_parse **head);
void					launch_builtin(t_shell *sh, t_parse *pa, t_job *job);
void					launch_bin(t_parse *p, t_job *job);
void					create_job(t_job **job, t_process **p, t_token *token);
void					create_process(t_process **p, t_token *token,
		t_shell *sh);
void					token_linker(t_shell *sh, t_job **job, t_process **p,
		t_token *token);
void					token_pipe(t_shell *sh, t_process **p, t_token *token);
int						get_num_process(t_process *process);
int						do_builtins(t_shell *sh, t_job *job, t_parse *parse);
int						do_exit(t_shell *sh, t_job *job, t_parse *parse);
int						job_success(t_job *job);

#endif
