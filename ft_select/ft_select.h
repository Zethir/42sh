/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:50:27 by cboussau          #+#    #+#             */
/*   Updated: 2016/07/26 20:46:33 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>

typedef struct			s_sel_lst
{
	char				*name;
	size_t				select;
	char				*save;
	size_t				len;
	size_t				line;
	int					index;
	struct s_sel_lst	*prev;
	struct s_sel_lst	*next;
}						t_sel_lst;

typedef struct			s_intel
{
	size_t				length;
	struct s_sel_lst	*tail;
	struct s_sel_lst	*head;
}						t_intel;

typedef struct			s_sel_struct
{
	size_t				size_last;
	size_t				col;
	size_t				row;
	size_t				nb_col;
	size_t				nb_item;
	size_t				coeff;
	size_t				count;
	size_t				realcol;
	size_t				len;
	size_t				delkey;
	size_t				size_w;
	char				buff[BUFF_SIZE];
	struct termios		term;
	struct s_intel		*node;
}						t_sel_struct;

t_intel				*init_sel_lst(char **argv);
t_intel				*add_sel_elem(t_intel *node, char *argv);
t_sel_struct		*init_sel_struct(char **argv);
t_sel_struct		*stock_sel_struct(t_sel_struct *info, int i);
char				*deal_with_term(t_sel_struct *info);
char				*do_select(char **argv, int id);
void				clean_lst(t_sel_struct *info);
void				print_opt(t_sel_lst *ptr, t_sel_struct *info);
void				deal_with_arrow_sel(t_sel_struct *info);
void				deal_with_col(t_sel_struct *info);
void				longest_word(t_sel_struct *info);
void				print_lst(t_sel_struct *info);
void				init_ptr(t_sel_struct *info);
void				del_elem_from_list(t_sel_struct *info);
void				left_arrow(t_sel_struct *info, t_sel_lst *ptr);
void				right_arrow(t_sel_struct *info, t_sel_lst *ptr);
void				check_size(t_sel_struct *info);
void				win_size(int id);
void				ft_signal_sel(int id);
void				sigcont_sel(int id);
void				sigtstp_sel(int id);
void				sigint_sel(int id);
void				start_end(t_sel_struct *info);
void				free_lst(t_sel_struct *info);
int					init_sel_term(t_sel_struct *info);
int					reset_sel_term(t_sel_struct *info);
int					exec_select(int argc, char **argv);

#endif
