/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:38:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/27 17:44:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <sh42.h>
# include <lexer.h>

void				print_parse_error(t_lex *lex);
void				print_error_opt(char *arg);
void				print_error_arg(void);
void				print_env_error(char *arg);
void				print_main_error(char *arg);
void				out_of_range_error(char **cmd);
void				no_command_error(char *arg);
void				print_identifier_error(t_env_hist *info, int i);
int					check_number_bis(char **cmd);
int					check_number(char **cmd);
int					check_alpha(char **cmd);
int					arg_in_dir(t_lst *node, char *arg);
int					numeric_error(char **cmd);
int					print_alpha_error(char **arg);
int					check_wrong_identifier(t_env_hist *info, int j);

#endif
