# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 14:41:44 by tvallee           #+#    #+#              #
#    Updated: 2016/09/13 14:19:17 by tvallee          ###   ########.fr        #
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

LIST_SRC		= ft_atabtoistr.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
				  ft_lstiter.c ft_lstlen.c ft_lstnew.c ft_lstnewcopy.c \
				  ft_lstpushback.c ft_lstremove.c ft_lsttotab.c \
				  ft_strlsttoitab.c

LOG_SRC			= ft_log.c

FT_GETOPT_SRC	= ft_getopt.c

GNL_SRC			= get_next_line.c

PRINT_SRC		= ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
				  ft_putendlfree_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
				  ft_putstr_fd.c

STR_TOOLS_SRC	= ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c \
				  ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c \
				  ft_strnequ.c ft_strnew.c ft_strsplit.c ft_strsplit_fromtab.c \
				  ft_strsub.c ft_strtrim.c

TAB_TOOLS_SRC	= ft_tabfree.c ft_tablen.c ft_tablineadd.c ft_tablinedel.c \
				  ft_tabtolst.c

TREE_SRC		= #btree_apply_infix.c btree_apply_prefix.c \
				  btree_apply_suffix.c btree_create_node.c btree_insert_data.c

MISC_SRC		= ft_itoa.c

SRC		= $(addprefix libc/, $(LIBC_SRC)) \
		  $(addprefix list/, $(LIST_SRC)) \
		  $(addprefix log/, $(LOG_SRC)) \
		  $(addprefix gnl/, $(GNL_SRC)) \
		  $(addprefix print/, $(PRINT_SRC)) \
		  $(addprefix str_tools/, $(STR_TOOLS_SRC)) \
		  $(addprefix tab_tools/, $(TAB_TOOLS_SRC)) \
		  $(addprefix tree/, $(TREE_SRC)) \
		  $(addprefix misc/, $(MISC_SRC)) \
		  $(addprefix ft_getopt/, $(FT_GETOPT_SRC))
NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-missing-noreturn\
		  -Wno-padded -Wno-unreachable-code -Wredundant-decls -g\
		  -Wmissing-declarations
SRC_DIR	= src
VPATH	= $(SRC_DIR)
INC		= -I./include
OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Creating archive library."
	@ar rc $(NAME) $(OBJ)
	@echo "Creating an index for archive library."

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<."
	@$(CC) $(CFLAGS) -c $< $(INC) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/libc $(OBJ_DIR)/log $(OBJ_DIR)/list $(OBJ_DIR)/gnl \
		$(OBJ_DIR)/print $(OBJ_DIR)/str_tools $(OBJ_DIR)/tab_tools \
		$(OBJ_DIR)/tree $(OBJ_DIR)/misc $(OBJ_DIR)/ft_getopt

clean:
	@echo "Deleting obj files."
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@echo "Deleting archive library."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
