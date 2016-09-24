# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2016/09/22 16:43:42 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 42sh

SRC_P 	= ./src/
HISTORY = $(SRC_P)history/
LST		= $(SRC_P)lst_func/
TOOLS	= $(SRC_P)tools/
ERRORS	= $(SRC_P)errors/
TERMCAP = $(SRC_P)termcaps/
LEXER	= $(SRC_P)lexer/
SRC		= $(SRC_P)main.c $(SRC_P)prompt.c $(SRC_P)termios.c $(SRC_P)free.c\
		  $(SRC_P)signal.c\
		  $(HISTORY)history.c $(HISTORY)history_option.c\
		  $(HISTORY)history_option2.c $(HISTORY)designator.c\
		  $(LST)lst_func.c $(LST)lst_func_bis.c $(LST)lst_token.c\
		  $(TOOLS)tools.c $(TOOLS)tools2.c $(TOOLS)tools3.c\
		  $(ERRORS)errors.c $(ERRORS)errors2.c $(ERRORS)errors3.c\
		  $(TERMCAP)termcap.c $(TERMCAP)termcapbis.c $(TERMCAP)termcapline.c\
		  $(LEXER)lexer.c $(LEXER)token.c $(LEXER)redir.c

FLAGS	= -Wall -Wextra -Werror
OBJ 	= $(SRC:.c=.o)
LIB		= ./libft/libft.a -ltermcap

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make fclean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean $(NAME)

.PHONY: all clean fclean re
