/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:46:22 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/30 16:34:02 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <lexer.h>

int			check_builtins(char *cmd);
int			do_cd(t_lst *node, char **arg);
int			do_echo(char **cmd);
int			deal_with_env(t_lex *lex, char **arg);
int			do_exit(char **arg);
int			do_setenv(t_lst *node, char **arg);
int			do_unsetenv(t_lst *node, char **arg);
void		print_env(t_lst *node);
void		restore_env(t_lst *node, char **save);
char		**deal_with_opt(t_lex *info, char **arg);



int			do_builtins(t_lex *lex);
void		do_export(t_env_hist *info);

#endif
