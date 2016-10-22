/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:47:18 by qdiaz             #+#    #+#             */
/*   Updated: 2016/10/22 12:13:58 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H
# define SH42_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/dir.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <libft.h>
# include <lexer.h>
# include <parser.h>
# include <funct.h>
# include <termcaps.h>

# define RED "[31m"
# define PURPLE "[1;35m"
# define GREEN "[32m"
# define CYAN "[0;36m"
# define BLUE "[1;34m"
# define RESET "[39m"

typedef struct		s_lst
{
	char			*line;
	char			*name;
	char			*user;
	char			*home;
	int				flag;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_dlist
{
	char			*str;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct		s_hub
{
	int				*stdio;
	int				closefd;
	struct s_dlist	*node;
	struct s_lst	*lst;
	struct s_lex	*lex;
	struct s_job	*job;
	struct termios	term;
	struct s_prompt	*prompt;
	struct s_parse	*parse;
}					t_hub;

t_lst				*init_lst(char **env);
t_lst				*delete_elem(t_lst *node);
t_dlist				*create_node(void);
t_hub				*stock_struct(t_hub *info, int i);
t_hub				*init_struct(char **env);
t_token				*hub_redir(t_hub *info, t_token *token);
void				truncate_redir(t_hub *info, t_token *token, char *filename);
void				append_redir(t_hub *info, t_token *token, char *filename);
void				heredoc(t_hub *info, char *code);
void				go_down_line(t_hub *info, char *buff);
void				go_up_line(t_hub *info, char *buff);
void				prompt_print(t_hub *info, char *buff);
void				get_missing_cmd(t_hub *info, t_lex *lex);
void				token_linker(t_hub *info, t_job *job, t_token *token);
void				token_pipe(t_hub *info, t_job *job, t_token *token);
void				init_stdio(t_hub *info);
void				exec_env(t_hub *info, char *arg, char **env_cpy);
void				exec_process(t_hub *info, t_process *process, int *iofile);
void				launch_builtin(t_hub *info, t_process *process);
void				launch_bin(t_hub *info, t_process *process);
void				create_job(t_job *job, t_token *token);
void				create_process(t_job *job, t_token *token, t_hub *info);
void				push_node(t_lst *node, t_lst **head);
void				push_node_bis(t_dlist **head, t_dlist *new_node);
void				go_to_end_list(t_hub *info);
void				add_history(t_hub *info);
void				deal_with_file(t_hub *info);
void				do_option(t_hub *info, char **cmd);
void				option_r(t_hub *info);
void				get_prompt(t_lst *node);
void				free_list(t_lst *node);
void				free_dlist(t_dlist *node);
void				free_hub(t_hub *info);
void				go_to_end(t_hub *info, char *buff);
void				exec_cmd(t_hub *info);
void				print_env(t_lst *node);
void				restore_env(t_lst *node, char **save);
void				parse_cmd(t_hub *info);
void				exec_pipe(t_hub *info);
void				print_identifier_error(t_hub *info, int i);
void				init_parse(t_hub *info, char *cmd);
void				deal_with_charac(t_hub *info, char *buff);
void				deal_with_space(t_hub *info, char *buff);
void				deal_with_backspace(t_hub *info, char *buff);
void				deal_with_delete(t_hub *info, char *buff);
void				deal_with_left(t_hub *info, char *buff);
void				deal_with_right(t_hub *info, char *buff);
void				deal_with_up(t_hub *info, char *buff);
void				deal_with_down(t_hub *info, char *buff);
void				start_copy_mode(t_hub *info, char *buff);
void				copy_string(t_hub *info, char *buff);
void				cut_string(t_hub *info, char *buff);
void				paste_string(t_hub *info, char *buff);
void				go_to_start_of_line(t_hub *info, char *buff);
void				go_to_end(t_hub *info, char *buff);
void				go_to_previous_word(t_hub *info, char *buff);
void				go_to_next_word(t_hub *info, char *buff);
void				deal_with_opt(t_hub *info, char **arg, char **env_cpy);
void				export_new_variable(t_hub *info, int i);
void				add_to_list(t_hub *info, t_lst *node, int j, int flag);
int					input_redir(t_hub *info, t_token *token, char *filename);
int					trunc_in_fd(t_hub *info, t_token *token, t_token *tmp);
int					do_exit(t_hub *info, char **arg);
int					check_lexer(t_hub *info, t_lex *lex);
int					out_fd_close(t_hub *info, t_token *token, t_token *tmp);
int					in_fd_close(t_hub *info, t_token *token, t_token *tmp);
int					do_designator(t_hub *info, char **cmd);
int					do_export(t_hub *info);
int					do_builtins(t_hub *info);
int					check_wrong_identifier(t_hub *info, int j);
int					do_cd(t_lst *node, char **arg);
int					do_setenv(t_lst *node, char **arg);
int					do_unsetenv(t_lst *node, char **arg);
int					arg_in_dir(t_lst *node, char *arg);
int					get_index(t_lst *node);
int					get_index(t_lst *node);
int					do_history(t_hub *info, char **cmd);
int					get_intel(t_lst *node, char *str);
int					check_lst(t_lst *node);
int					reset_term(t_hub *info);
int					init_term(t_hub *info);
int					deal_with_env(t_hub *info, char **arg);
int					create_new_variable(t_hub *info);
int					check_local_variable(t_hub *info, int i, int flag);
char				*get_home(t_lst *node);
char				*deal_with_termcap(t_hub *info);
char				*join_env(char **arg);
char				**get_env(t_lst *lst);

#endif
