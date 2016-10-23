/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:50:30 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/22 18:29:00 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# define ARROW_LEFT ((buff[0] == 27 && buff[1] == 91 && buff[2] == 68))
# define ARROW_RIGHT ((buff[0] == 27 && buff[1] == 91 && buff[2] == 67))
# define WHITE_SPACE ((*buff == ' '))
# define BACK_SPACE ((*buff == 127))
# define CHARACTERE ((*buff >= '!' && *buff <= '~'))
# define ARROW_UP ((buff[0] == 27 && buff[1] == 91 && buff[2] == 65))
# define ARROW_DOWN ((buff[0] == 27 && buff[1] == 91 && buff[2] == 66))
# define DELETE ((buff[0] == 27 && buff[1] == 91 && buff[2] == 51))
# define ESCAPE ((buff[0] == 4 && buff[1] == -1 && buff[2] == 127))
# define END ((buff[0] == 27 && buff[1] == 91 && buff[2] == 70))
# define HOME ((buff[0] == 27 && buff[1] == 91 && buff[2] == 72))
# define PREV_WORD_1 ((buff[0] == 27 && buff[1] == 27))
# define PREV_WORD_2 ((buff[2] == 91 && buff[3] == 68))
# define PREV_WORD ((PREV_WORD_1 && PREV_WORD_2))
# define NEXT_WORD_1 ((buff[0] == 27 && buff[1] == 27))
# define NEXT_WORD_2 ((buff[2] == 91 && buff[3] == 67))
# define NEXT_WORD ((NEXT_WORD_1 && NEXT_WORD_2))
# define COPY_MODE ((buff[0] == -30 && buff[1] == -120 && buff[2] == -102))
# define COPY_STRING ((buff[0] == -62 && buff[1] == -91))
# define PASTE_STRING ((buff[0] == -49 && buff[1] == -128))
# define CUT_STRING ((buff[0] == -30 && buff[1] == -120 && buff[2] == -126))
# define UP_CMD_1 ((buff[0] == 27 && buff[1] == 27))
# define UP_CMD_2 ((buff[2] == 91 && buff[3] == 65))
# define UP_CMD ((UP_CMD_1 && UP_CMD_2))
# define DOWN_CMD_1 ((buff[0] == 27 && buff[1] == 27))
# define DOWN_CMD_2 ((buff[2] == 91 && buff[3] == 66))
# define DOWN_CMD ((DOWN_CMD_1 && DOWN_CMD_2))

typedef struct	s_prompt
{
	char		*cmd;
	int			i;
	int			copy_mode;
	int			cursor_start;
	int			cursor_end;
	char		*copy_str;
	size_t		win_size;
}				t_prompt;

t_prompt		*init_prompt();
void			free_prompt(t_prompt **info);

#endif
