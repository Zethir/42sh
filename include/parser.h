/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:20:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 16:03:05 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <lexer.h>
/*
	AND = 1,
	OR = 2, 
	PIPE = 3,
	R_ADD = 4,
	R_OUT = 5,
	R_OFDCLOSE = 6,
	R_OFD = 7,
	R_HEREDOC = 8,
	R_IN = 9,
	R_IFDCLOSE = 10,
	R_IFD = 11,
*/

typedef struct		s_parse
{
	char			**right_path;
	char			**env;
	char			*bin_path;
	pid_t			pid;
	int				nb_pipe;
}					t_parse;

int			get_index(t_lst *node);
int			list_browser(t_lex *lex);
int			init_parse(t_lex *lex, t_env_hist *env_hist);


#endif
