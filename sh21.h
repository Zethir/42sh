/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:44:03 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/21 18:00:29 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H
# define BUFF_SIZE 4

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

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
	struct s_lst	*next;
}					t_lst;

typedef struct		s_dlist
{
	char			*str;
	int				i;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct		s_struct
{
	char			**cmd;
	char			**right_path;
	char			**env;
	char			**arg;
	char			buff[BUFF_SIZE];
	int				num;
	pid_t			pid;
	struct s_dlist	*node;
	struct s_lst	*lst;
	struct termios	term;
}					t_struct;

t_lst				*delete_elem(t_lst *node);
t_lst				*init_lst(char **env);
t_dlist				*create_node(void);
t_struct			*init_struct(char **env);
t_struct			*stock_struct(t_struct *info, int i);
void				push_node_bis(t_dlist **head, t_dlist *new_node);
void				close_pipefds(int pipefds[], int num);
void				wait_for_child(int num);
void				add_elem(t_lst *node, char *arg);
void				push_node(t_lst *node, t_lst **head);
void				get_prompt(t_lst *node);
void				free_list(t_lst *node);
void				print_env(t_lst *node);
void				color(char *color, char *str);
void				restore_env(t_lst *node, char **save);
void				free_list(t_lst *node);
void				print_error_opt(char *arg);
void				print_error_arg(void);
void				print_env_error(char *arg);
void				print_main_error(char *arg);
void				no_command_error(char *arg);
void				print_right_error(t_lst *node, char *arg);
void				deal_with_redirection(t_struct *ptr);
void				data_series(t_struct *ptr, int i);
void				redirection_in(t_struct *ptr, int fd, int i);
void				exec_cmd(t_struct *ptr, char **str);
void				redirection_err_out(t_struct *ptr, int i);
void				ft_signal(int id);
void				sigcont(int id);
void				sigtstp(int id);
void				sigquit(int id);
void				deal_with_others(t_struct *info);
void				go_to_end(t_struct *info);
void				deal_with_file(t_struct *info);
void				add_history(t_struct *info);
void				tab_completion(t_struct *info, char *str);
void				do_option(t_struct *info, char **cmd);
void				out_of_range_error(char **cmd);
void				option_r(t_struct *info, char *str);
void				do_builtins(t_struct *info);
void				free_dlist(t_dlist *node);
int					do_history(t_struct *info, char **cmd);
int					arg_in_dir(t_lst *node, char *arg);
int					print_alpha_error(char **arg);
int					check_lst(t_lst *node);
int					get_intel(t_lst *node, char *str);
int					get_intel_bis(t_lst *node, char *str);
int					do_exit(char **arg);
int					deal_with_env(t_struct *info, char **arg);
int					do_setenv(t_lst *node, char **arg);
int					do_unsetenv(t_lst *node, char **arg);
int					do_cd(t_lst *node, char **arg);
int					get_index(t_lst *node);
int					ft_strccmp(const char *s1, const char *s2, char c);
int					check_caract(char *str, char c);
int					init_term();
int					reset_term();
int					deal_with_pipe(t_struct *info, char *arg);
int					start_pipe(int pipefds[], int num);
int					check_for_chevron(t_struct *ptr);
int					check_for_parenth(char *arg);
int					do_echo(char **cmd);
int					check_builtins(t_struct *info);
int					numeric_error(char **cmd);
char				*split_line(char *line);
char				*get_home(t_lst *node);
char				**deal_with_opt(t_struct *info, char **arg);
char				**malloc_tab(char **arg);
char				*deal_with_termcap(t_struct *info);
char				**split_path(t_lst *node);
char				*check_path(char **path, char *arg);
char				**get_env(t_lst *node);
char				**save_command(t_struct *ptr);

#endif
