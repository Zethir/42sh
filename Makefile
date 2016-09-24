# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboussau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/24 14:53:02 by cboussau          #+#    #+#              #
#    Updated: 2016/09/24 14:53:48 by cboussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

C_DIR =	src
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIRS) -type f -follow -print | grep "\.c")

O_DIR =	.tmp/obj
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft/include
LIB = -Llibft -lft -ltermcap

all: $(NAME)

$(NAME): $(O_FILES)
		make -C libft
			gcc $(FLAGS) $^ $(LIB) $(SRCI) -o $@

$(O_DIR)%.o: $(C_DIR)%.c
		@mkdir -p $(O_DIRS) $(O_DIR)
			gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
		@make clean -C libft
			@rm -rf $(O_DIR)

fclean: clean
		@make fclean -C libft
			@rm $(NAME) || true
				@rm -rf .tmp/

re: fclean all

.PHONY: clean all fclean re
