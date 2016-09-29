/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:36:57 by qdiaz             #+#    #+#             */
/*   Updated: 2016/09/29 14:01:44 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <sh42.h>

int			check_builtins(t_lex *lex);
int			do_cd(t_lst *node, char **arg);
int			do_echo(char **cmd);
int			deal_with_env(t_env_hist *info, char **arg);
int			do_exit(char **arg);
int			do_setenv(t_lst *node, char **arg);
int			do_unsetenv(t_lst *node, char **arg);
void		print_env(t_lst *node);
void		restore_env(t_lst *node, char **save);
char		**deal_with_opt(t_env_hist *info, char **arg);



int			do_builtins(t_lex *lex);
void		do_export(t_env_hist *info);

#endif