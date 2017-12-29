# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/05 11:37:16 by ojerroud          #+#    #+#              #
#    Updated: 2017/07/05 14:45:25 by ojerroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/check.c src/ft_utile.c src/main.c src/solve.c src/solve_2.c

OBJ = src/check.o src/ft_utile.o src/main.o src/solve.o src/solve_2.o

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@echo compiling fillit..
	@make -C libft
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIB)
	@echo done.

clean:
	@echo clean in progress..
	@/bin/rm -f $(OBJ)
	@make clean -C libft
	@echo done.

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re: fclean all
