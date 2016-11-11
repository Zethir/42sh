/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:37:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/11 17:46:26 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <termcap.h>
# include <shell.h>

typedef enum		e_token_type
{
	AND = 1,
	OR = 2,
	PIPE = 3,
	R_ADD = 4,
	R_TRUNC = 6,
	R_TRUNC_FD_CLOSE = 7,
	R_TRUNC_FD = 8,
	HEREDOC = 9,
	R_IN = 10,
	R_IN_FD_CLOSE = 11,
	R_IN_FD = 12,
	SEPARATOR = 13
}					t_token_type;

typedef struct		s_token
{
	char			*cmd;
	int				fd[2];
	int				token_value;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct		s_token_ht
{
	struct s_token	*head;
	struct s_token	*tail;
}					t_token_ht;

typedef struct		s_lex
{
	char			*line;
	int				fd[2];
	int				hd;
	int				tl;
	int				lencmd;
	struct s_token	*token;
}					t_lex;

t_lex				*init_lexer_struct(void);
t_token				*init_token(t_lex *lex, t_token_ht *token, char *cmd,
		int val);
t_token				*hub_redir(t_shell *sh, t_token *token);
t_token_ht			*add_token(t_lex *lex, t_token_ht *token_ht, char *cmd,
		int val);
t_token				*check_lexer(t_lex *lex, t_token_ht *token_ht, t_shell *sh);
t_token				*cmd_is_empty(t_lex *lex, t_token *new_elem, int val);
void				free_struct_lex(t_lex **lex);
void				free_lex(t_lex **lex);
void				free_token_ht(t_token_ht **token);
void				get_first_fd(t_lex *lex, int i);
void				get_missing_cmd(t_lex *lex, t_token_ht *token_ht,
		t_shell *sh);
void				truncate_redir(t_shell *sh, t_token *token, char *filename);
void				append_redir(t_shell *sh, t_token *token, char *filename);
void				parse_cmd(t_shell *sh, t_token *token);
void				dollar_symbol(t_shell *sh, t_lex *lex);
int					get_second_fd(t_lex *lex, int i);
int					is_redir(t_lex *lex, t_token_ht *token_ht, int i);
int					is_token(t_lex *lex, t_token_ht *token_ht, int i);
int					is_replace_bis(t_lex *lex, t_token_ht *t, int i, char *tmp);
int					is_in_bis(t_lex *lex, t_token_ht *t, int i, char *tmp);
int					list_browser(t_lex *lex);
int					input_redir(t_shell *sh, t_token *token, char *filename);
int					trunc_in_fd(t_shell *sh, t_token *token, t_token *tmp);
int					out_fd_close(t_shell *sh, t_token *token, t_token *tmp);
int					in_fd_close(t_shell *sh, t_token *token, t_token *tmp);

#endif
