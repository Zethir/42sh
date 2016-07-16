# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 13:00:32 by qdiaz             #+#    #+#              #
#    Updated: 2016/03/17 10:55:40 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_atoi.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnstr.c\
	ft_strstr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strrchr.c\
	ft_bzero.c\
	ft_memset.c\
	ft_isprint.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcat.c\
	ft_putstr.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putendl.c\
	ft_putstr_fd.c\
	ft_putchar_fd.c\
	ft_putnbr_fd.c\
	ft_putendl_fd.c\
	ft_strclr.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_itoa.c\
	ft_lstadd.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstnew.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_isspace.c\
	ft_strrev.c\
	ft_swap.c\
	ft_strupcase.c\
	ft_strdowncase.c\
	ft_strcdup.c\
	ft_strndup.c\
	ft_strclen.c\
	get_next_line.c\
	ft_strnjoin.c\
	ft_tablen.c\
	ft_tabswap.c\
	ft_freetab.c\
	ft_tabdup.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
