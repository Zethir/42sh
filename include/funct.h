/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:38:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/19 15:03:16 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCT_H
# define FUNCT_H

void				print_error_opt(char *arg);
void				print_error_arg(void);
void				print_env_error(char *arg);
void				print_main_error(char *arg);
void				out_of_range_error(char **cmd);
void				no_command_error(char *arg);
void				ft_signal(int id);
void				sigquit(int id);
void				sigint(int id);
void				sigcont(int id);
void				sigtstp(int id);
void				close_pipefds(int pipefds[], int num);
void				wait_for_child(int num);
void				color(char *color, char *str);
int					check_number_bis(char **cmd);
int					check_number(char **cmd);
int					check_alpha(char **cmd);
int					numeric_error(char **cmd);
int					print_alpha_error(char **arg);
int					start_pipe(int pipefds[], int num);
int					check_builtins(char *cmd);
int					do_echo(char **cmd);
int					check_caract(char *str, char c);
int					check_for_parenth(char *arg);
char				*split_line(char *line);
char				**malloc_tab(char **arg);

#endif
