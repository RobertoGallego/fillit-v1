# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groberto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 17:46:34 by groberto          #+#    #+#              #
#    Updated: 2018/11/26 17:53:06 by groberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

SRC		= ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_itoa.c \
		  ft_strsplit.c \
		  ft_strlcat.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_abs.c \
		  ft_ismaj.c \
		  ft_ismin.c \
		  ft_recursive_power.c \
		  ft_sqrt.c \
		  ft_strtolower.c \
		  ft_strtoupper.c \
		  ft_swap.c \

DIR		= ./

all : $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC) -I$(DIR)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)
	rm -f *.o

re: fclean all

.PHONY: clean clean
