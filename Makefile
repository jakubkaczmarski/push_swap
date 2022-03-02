# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 16:29:15 by jkaczmar          #+#    #+#              #
#    Updated: 2022/03/02 15:01:24 by jkaczmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: push_swap

push_swap:
	gcc -Wall -Wextra -Werror -o push_swap operations.c stack_helper.c ft_itoa.c stack_managment.c push_swap.c check_input.c help_func.c rotating.c sorting.c stack_intructions.c swaping_pushing.c 
clean:
	@rm -f push_swap
fclean:
	@rm -f push_swap
re: fclean all

.PHONY: all clean fclean re