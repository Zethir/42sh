/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:20:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/08 14:01:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
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
	char			**argv;
	char			*right_path;
	char			**env;
	pid_t			pid;
	int				pipefd[2];
	int				bl;
}					t_parse;

void	free_parse(t_parse *parse);

#endif
