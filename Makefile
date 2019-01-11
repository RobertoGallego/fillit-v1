# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groberto <groberto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 14:21:53 by jbeall            #+#    #+#              #
#    Updated: 2019/01/11 17:09:21 by groberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra -g
SRC = ./src/main.c ./src/reader.c
INCLUDES = ./includes
LIBRARIES = ./libft/libft.a

$(NAME):
	@make -C ./libft --no-print-directory
	@echo "Creating fillit executable..."
	@clang -o $(NAME) $(FLAGS) $(SRC) $(LIBRARIES) -I$(INCLUDES) -O3 
	@echo "\033[92mdone!\033[0m"
all: $(NAME)
test: fclean
	make -C ./libft --no-print-directory
	gcc -o $(NAME) $(FLAGS) -g ./fillit_extras.c $(SRC) -I$(INCLUDES) -O3
	./fillit ./maps/valid4
clean:
	@echo "cleaning..."
	@make clean -C ./libft --no-print-directory
	@echo "libft object files removed!"
fclean: clean 
	@rm -f $(NAME)
	@echo "fillit executable removed!"
	@make fclean -C ./libft --no-print-directory
re: fclean all
