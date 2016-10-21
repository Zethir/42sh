/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:37:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/21 13:49:03 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum			e_token_type
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
}						t_token_type;

typedef struct			s_token
{
	char				*cmd;
	int					*fd;
	int					token_value;
	struct s_token		*next;
}						t_token;

typedef struct			s_lex
{
	char				*line;
	int					*fd;
	int					hd;
	int					tl;
	struct s_token		*token;
}						t_lex;

t_lex					*init_lexer_struct(void);
t_token					*init_token_struct(void);
void					print_parse_error(t_lex *lex);
void					free_struct_lex(t_lex *lex);
void					free_lex(t_lex *lex);
void					get_first_fd(t_lex *lex, int i);
int						add_token(t_lex *lex, char *cmd, int val);
int						get_second_fd(t_lex *lex, int i);
int						is_redir(t_lex *lex, int i);
int						is_token(t_lex *lex, int i);
int						is_add_bis(t_lex *lex, char *str, int i);
int						is_in_bis(t_lex *lex, char *str, int i);
int						is_replace_bis(t_lex *lex, char *str, int i);
int						is_heredoc_bis(t_lex *lex, char *str, int i);
int						list_browser(t_lex *lex);

#endif
