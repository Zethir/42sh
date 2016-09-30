/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:38:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/30 17:35:43 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

void				print_error_opt(char *arg);
void				print_error_arg(void);
void				print_env_error(char *arg);
void				print_main_error(char *arg);
void				out_of_range_error(char **cmd);
void				no_command_error(char *arg);
int					check_number_bis(char **cmd);
int					check_number(char **cmd);
int					check_alpha(char **cmd);
int					numeric_error(char **cmd);
int					print_alpha_error(char **arg);

#endif
