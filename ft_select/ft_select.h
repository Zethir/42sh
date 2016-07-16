/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:32:28 by qdiaz             #+#    #+#             */
/*   Updated: 2016/07/16 18:56:41 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>

# define BUFFER *(unsigned int *)buffer

typedef struct		s_dblist
{
	char			*value;
	int				select;
	int				line;
	struct s_dblist	*next;
	struct s_dblist	*prev;
	int				len;
}					t_dblist;

typedef enum		e_enum
{
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	ESC_KEY = 27,
	SPACE_KEY = 32,
	DEL_KEY = 127,
	RET_KEY = 10,
	SUP_KEY = 2117294875,
	HOME_KEY = 4741915,
	END_KEY = 4610843,
	PAGE_UP_KEY = 2117425947,
	PAGE_DOWN_KEY = 2117491483,
	TAB_KEY = 9,
	CRTL_A_KEY = 1
}					t_enum;

typedef struct		s_term
{
	struct termios	term;
	char			*name_term;
	int				fd;
	int				nb_col;
	int				nb_row;
	int				enter;
	int				count[2];
	char			**ret_tab;
	struct s_term	*first;
	t_dblist		*dblist;
}					t_term;

int					ft_myputchar(int c);
int					ft_init_termios(t_term *all);
int					ft_end_termios(t_term *all);
void				screen_clear(void);
t_dblist			*lst_init(void);
t_dblist			*fill_list(char *str);
void				add_link(t_term *termi, t_dblist *list);
void				arg_to_list(char **argv, t_term *termi);
void				count_col(t_term *termi);
void				ft_print(t_term *termi);
int					ft_check_size(t_term *termi);
void				ft_resize(void);
t_term				*ft_stock(t_term *termi, int i);
void				ft_goto_begin(t_term *termi);
void				ft_goto_end(t_term *termi);
void				ft_space_key(t_term *termi);
int					ft_delete(t_term *termi);
void				ft_tab_key(t_term *termi);
void				ft_up(t_term *termi);
void				ft_down(t_term *termi);
void				ft_deselect_all(t_term *termi);
void				ft_select_all(t_term *termi);
void				ft_stock_tab(t_term *termi);
void				ft_return_key(t_term *termi);
int					ft_key(t_term *termi);
void				ft_print_enter(t_term *termi);
int					max_size(t_term *termi);
int					list_size(t_term *termi);
int					nb_max_col(t_term *termi, int max);
int					strlenint(char *str);
int					ft_op_display(t_term *termi, int i, int max);
void				ft_signal(void);
void				ft_left(t_term *termi);
void				ft_right(t_term *termi);

#endif
