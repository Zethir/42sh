/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:47:18 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/30 17:15:42 by cboussau         ###   ########.fr       */
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
# include <errors.h>
# include <builtins.h>
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
	int				i;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct		s_hub
{
	pid_t			pid;
	struct s_dlist	*node;
	struct s_lst	*lst;
	struct lexer	*lex;
	struct parse	*parse;
	struct termios	term;
}					t_hub;

t_lst				*init_lst(char **env);
t_lst				*delete_elem(t_lst *node);
t_dlist				*create_node(void);
t_hub				*stock_struct(t_hub *info, int i);
t_hub				*init_struct(char **env);
void				push_node(t_lst *node, t_lst **head);
void				push_node_bis(t_dlist **head, t_dlist *new_node);
void				go_to_end_list(t_hub *info);
void				add_history(t_hub *info);
void				deal_with_file(t_hub *info);
void				do_option(t_hub *info, char **cmd);
void				add_to_file(t_hub *info, char *str);
void				option_r(t_hub *info, char *str);
void				do_designator(t_hub *info, char **cmd);
void				ft_signal(int id);
void				sigquit(int id);
void				sigint(int id);
void				sigcont(int id);
void				sigtstp(int id);
void				get_prompt(t_lst *node);
void				close_pipefds(int pipefds[], int num);
void				wait_for_child(int num);
void				add_elem(t_lst *node, char *arg);
void				free_list(t_lst *node);
void				free_dlist(t_dlist *node);
void				color(char *color, char *str);
void				deal_with_others(t_hub *info, char *buff);
void				go_to_end(t_hub *info, char *buff);
void				exec_cmd(t_hub *info);
int					init_parse(t_hub *info);
int					get_index(t_lst *node);
int					get_index(t_lst *node);
int					start_pipe(int pipefds[], int num);
int					do_history(t_hub *info, char **cmd);
int					get_intel(t_lst *node, char *str);
int					check_lst(t_lst *node);
int					reset_term(t_hub *info);
int					init_term(t_hub *info);
int					check_caract(char *str, char c);
int					ft_strccmp(const char *s1, const char *s2, char c);
int					check_for_parenth(char *arg);
char				*split_line(char *line);
char				*get_home(t_lst *node);
char				**malloc_tab(char **arg);
char				*deal_with_termcap(t_hub *info);

#endif
