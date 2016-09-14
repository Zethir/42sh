# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2016/09/14 10:31:01 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC_SRC		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				  ft_isdigit.c ft_isprint.c ft_isspace.c ft_memalloc.c \
				  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
				  ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c \
				  ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
				  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c \
				  ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c \
				  ft_toupper.c

SRC		= $(addprefix libc/, $(LIBC_SRC))
NAME	= 42sh
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
SRC_DIR	= src
VPATH	= $(SRC_DIR)
INC		= -I./include
OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Builting library."
	@make -C libft
	@echo "Creating an index for archive library."
	gcc -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) $(CFLAGS) -c $< $(INC) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/libc

clean:
	@echo "Deleting obj files."
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@echo "Deleting archive library."
	@rm -f $(NAME)

re: fclean all

run_dev: $(NAME)
	@MallocScribble=t ./$(NAME)

.PHONY: all clean fclean re
