/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:20:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 17:36:23 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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
	int				bl;
}					t_parse;


#endif
