/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:37:43 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/20 12:00:20 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/libft.h"
# include "sh42.h"

typedef struct		s_token
{
	char			*name;
	int				value;
	struct s_token	*next;
}					t_token;

typedef struct		s_cmd
{
	char			*str;
	int				index;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_lex
{
	char			*line;
	char			**arg;
	struct s_token	*token;
	struct s_cmd	*cmd;
}					t_lex;

#endif
