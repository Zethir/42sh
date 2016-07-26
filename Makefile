# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboussau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/24 14:55:22 by cboussau          #+#    #+#              #
#    Updated: 2016/07/26 20:58:35 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SELECT = ./ft_select/

SRC = main.c prompt.c env.c tools.c env_arg.c errors.c setenv.c exit.c\
	  unsetenv.c cd.c check.c errors2.c lst_func.c tools2.c termcap.c termios.c\
	  termcapbis.c termcapline.c pipe.c tools3.c redirections.c redirections2.c\
	  signal.c lst_func_bis.c echo.c history.c auto_complete.c history_option.c \
	  history_option2.c builtins.c free.c designator.c errors3.c\
	  $(SELECT)exec_select.c\
	  $(SELECT)lst_function.c\
	  $(SELECT)termios.c\
	  $(SELECT)termcap.c\
	  $(SELECT)termcaparrow.c\
	  $(SELECT)termcaprint.c\
	  $(SELECT)deal_with_size.c\
	  $(SELECT)signal2.c\
	  $(SELECT)tools.c

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
