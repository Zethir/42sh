/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 10:50:30 by cboussau          #+#    #+#             */
/*   Updated: 2016/09/21 13:34:12 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "sh42.h"

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
# define PREV_WORD ((buff[0] == 27 && buff[1] == 27 && buff[2] == 91 && buff[3] == 68))
# define NEXT_WORD ((buff[0] == 27 && buff[1] == 27 && buff[2] == 91 && buff[3] == 67))

void				deal_with_others(t_struct *info, char *buff);
void				go_to_end(t_struct *info, char *buff);
char				*deal_with_termcap(t_struct *info);

#endif
