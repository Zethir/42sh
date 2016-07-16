# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/19 11:56:04 by qdiaz             #+#    #+#              #
#    Updated: 2016/07/16 19:00:17 by cboussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
SRC = main.c init_term.c tools.c ft_select.c ft_action.c ft_key.c\
	  ft_print.c ft_size.c list_tools.c tools2.c ft_signal.c\
	  ft_move.c
OBJ = $(SRC:.c=.o)
LIB = ../libft/libft.a
FLAGS = -Wall -Wextra -Werror -g

.SILENT:

$(NAME): $(OBJ)
	echo "\\033[1;34mGenerating objects... Please wait\\033[0;39m"
	make -C ../libft
	echo "\\033[36mcompiling $(NAME)...\\033[0;39m"
	gcc $(FLAGS) -ltermcap $(OBJ) $(LIB) -o $(NAME)
	echo "\\033[32m$(NAME) has been created !\\033[0;39m"

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C ../libft/ clean
	echo "\\033[31mobjects files has been removed !\\033[0;39m"

fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft
	echo "\\033[31m$(NAME) has been removed !\\033[0;39m"

re: fclean $(NAME)

.PHONY : all clean fclean re
