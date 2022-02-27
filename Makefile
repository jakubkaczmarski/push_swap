# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 16:29:15 by jkaczmar          #+#    #+#              #
#    Updated: 2022/02/27 20:50:24 by jkaczmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: push_swap

push_swap:
	gcc -Wall -Wextra -Werror -o push_swap operations.c stack_helper.c ft_itoa.c stack_managment.c push_swap.c check_input.c help_func.c rotating.c sorting.c stack_intructions.c swaping_pushing.c ft_printf/ft_printf.c ft_printf/ft_putchar.c	ft_printf/ft_putstr_fd.c	ft_printf/typecheck.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	ft_printf/ft_puttinghex.c	ft_printf/ft_printstuff.c
clean:
	@rm -f push_swap
fclean:
	@rm -f push_swap
re: fclean all

.PHONY: all clean fclean re