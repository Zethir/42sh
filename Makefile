# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboussau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/24 14:55:22 by cboussau          #+#    #+#              #
#    Updated: 2016/09/10 11:56:27 by cboussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SELECT = ./ft_select/
BUILTINS = ./builtins/
HISTORY = ./history/
ERRORS = ./errors/
TOOLS = ./tools/
REDIR = ./redirections/
TERM = ./termcaps/
LST = ./lst_func/

SRC = main.c prompt.c check.c termios.c pipe.c signal.c auto_complete.c free.c\
		$(BUILTINS)env_arg.c\
		$(BUILTINS)cd.c\
		$(BUILTINS)builtins.c\
		$(BUILTINS)env.c\
		$(BUILTINS)setenv.c\
		$(BUILTINS)unsetenv.c\
		$(BUILTINS)exit.c\
		$(BUILTINS)echo.c\
		$(BUILTINS)export.c\
		$(HISTORY)history.c\
		$(HISTORY)history_option.c\
		$(HISTORY)history_option2.c\
		$(HISTORY)designator.c\
		$(SELECT)exec_select.c\
		$(SELECT)lst_function.c\
		$(SELECT)termios.c\
		$(SELECT)termcap.c\
		$(SELECT)termcaparrow.c\
		$(SELECT)termcaprint.c\
		$(SELECT)deal_with_size.c\
		$(SELECT)signal2.c\
		$(SELECT)tools.c\
		$(ERRORS)errors.c\
		$(ERRORS)errors2.c\
		$(ERRORS)errors3.c\
		$(TOOLS)tools.c\
		$(TOOLS)tools2.c\
		$(TOOLS)tools3.c\
		$(REDIR)redirections.c\
		$(REDIR)redirections2.c\
		$(TERM)termcap.c\
		$(TERM)termcapline.c\
		$(TERM)termcapbis.c\
		$(LST)lst_func.c\
		$(LST)lst_func_bis.c

OBJ = $(SRC:.c=.o)
	LIB = ./libft/libft.a -ltermcap
	FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

all : $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean $(NAME)

.PHONY : all clean fclean re
