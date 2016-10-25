# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboussau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/24 14:53:02 by cboussau          #+#    #+#              #
#    Updated: 2016/10/25 18:21:25 by cboussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

C_DIR =	src
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIRS) -type f -follow -print | grep "\.c")

O_DIR =	.tmp/obj
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iinclude -Ilibft/include
LIB = -Llibft -lft -ltermcap

.SILENT:

all: $(NAME)

$(NAME): $(O_FILES)
		echo "\\033[1;34mCompiling LIBFT...\\033[0;39m"
		make -C libft
		gcc $(FLAGS) $^ $(LIB) -o $@
		echo "\\033[32m$(NAME) has been created !\\033[0;39m"

$(O_DIR)%.o: $(C_DIR)%.c
		mkdir -p $(O_DIRS) $(O_DIR)
		gcc $(FLAGS) $(INCLUDES) -o $@ -c $<
		echo "\\033[1;34mGenerating objects... Please wait\\033[0;39m"

clean:
		make clean -C libft
		rm -rf $(O_DIR)
		echo "\\033[31mobjects files has been removed !\\033[0;39m"

fclean: clean
		make fclean -C libft
		rm $(NAME) || true
		rm -rf .tmp/
		echo "\\033[31m$(NAME) has been removed !\\033[0;39m"

re: fclean all

.PHONY: clean all fclean re
