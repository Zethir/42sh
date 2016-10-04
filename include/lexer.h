/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:37:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/04 15:56:23 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct			s_token
{
	char				*name;
	int					value;
	struct s_token		*next;
}						t_token;

typedef struct			s_lex
{
	char				*line;
	int					hd;
	int					tl;
	struct s_token		*token;
}						t_lex;

t_lex				*init_lexer_struct(void);
t_token				*init_token_struct(void);
void				add_token(t_lex *lex, char *new_token, int val);
void				check_lexer(t_lex *info);
void				print_parse_error(t_lex *lex);
void				free_lex(t_lex *lex);
void				free_struct_lex(t_lex *lex);
int					is_redir(t_lex *lex, int i);
int					is_token(t_lex *lex, int i);
int					is_add_bis(t_lex *lex, char *str, int i);
int					is_in_bis(t_lex *lex, char *str, int i);
int					is_replace_bis(t_lex *lex, char *str, int i);
int					is_heredoc_bis(t_lex *lex, char *str, int i);
int					list_browser(t_lex *lex);

#endif
