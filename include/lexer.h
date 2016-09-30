/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:37:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 17:16:09 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <sh42.h>

typedef struct			s_token
{
	char				*name;
	int					value;
	struct s_token		*next;
}						t_token;

typedef struct			s_cmd
{
	char				**argv;
	int					index;
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_lex
{
	char				*line;
	char				**arg;
	int					hd;
	int					tl;
	struct s_token		*token;
	struct s_cmd		*cmd;
}						t_lex;

t_lex				*init_lexer_struct(void);
void				add_token(t_lex *lex, char *new_token, int val);
void				add_cmd(t_lex *lex, char *new_cmd, int index);
void				check_lexer(t_lex *info);
int					is_redir(t_lex *lex, int i);
int					is_token(t_lex *lex, int i);
int					is_add_bis(t_lex *lex, char *str, int i);
int					is_in_bis(t_lex *lex, char *str, int i);
int					is_replace_bis(t_lex *lex, char *str, int i);
int					is_heredoc_bis(t_lex *lex, char *str, int i);
int					list_browser(t_lex *lex);

#endif
