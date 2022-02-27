/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:32:54 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:25:50 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

#include "ft_printf/ft_printf.h"

typedef struct sStack
{
	int top;
	unsigned capacity;
	int *array;
	/* data */
} tstack;

tstack * createstack(unsigned int capacity);
//###Stack instructions###
int		isfull(tstack* stack);
int		isempty(tstack* stack);
int		pop(tstack* stack);
void	push(tstack* stack, int topush);
int		peek(tstack* stack);
void	printstack(tstack* stack);
//###Push_swap_instructions###
//Swaping
void	sa(tstack* stack, int i);
void	sa_rra_op(tstack *stack_a, tstack *stack_a_cpy);
void	sb(tstack* stack, int i);
void	ss(tstack* a, tstack* b);
void	sa_operation(tstack* stack, tstack* stack_cpy);
//Pushing
void	pa(tstack* a, tstack *b, int i);
void	pa_op(tstack *stack_a, tstack *stack_b, tstack *stack_a_cpy, tstack *bcpy);
void	pb_op(tstack *stack_a, tstack *stack_b, tstack *stack_a_cpy, tstack *bcpy);
void	pb(tstack* a, tstack *b, int i);
//Rotating
void	ra(tstack* a, int num);
void	rb(tstack* b, int num);
void	rr(tstack* a, tstack *b);
void ra_operation(tstack *stack_a, tstack *stack_a_cpy);
//Reverse rotating
void	rra(tstack* a, int num);
void	rrb(tstack* a, int num);
void	rrr(tstack *a, tstack *b);
void double_rra_op(tstack *stack_a, tstack *stack_a_cpy);
void	rra_operation(tstack *stack_a, tstack *stack_a_cpy);
//###Input checking###
int		check_for_int_overflow(int num, char *str);
int		check_input(char *str,tstack **stack_a);
int		check_for_duplicates(tstack **stack_a);
//###Sorting Part###//
tstack	*cpy_stack(tstack *stack_a, tstack *cpy_stack_a);
void	change_arr_values(tstack **input_stack, tstack** stack_a_copy, tstack* sorted_cpy);
void	radix_sort(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b, tstack **stack_b_cpy);
void	sort_small_arr_3(tstack **stack_sorted, tstack **actual_stack);
void	sort_small_arr_2(tstack **stack_sorted, tstack **actual_stack);
void	sort_small_arr_4(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b_cpy, tstack **stack_b);
void	sort_small_arr_5(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b_cpy, tstack **stack_b);
void	rotate_till_value_at_top(tstack **stack_sorted, tstack **actual_stack, int val);
int		issorted(tstack *stack);
int		issorted_desc(tstack *stack);
//###Array with Indexes creation ###//
void	indexedarr(tstack *stack_cpy);
//###Helper Func###
int	freeall(tstack *stack_a, tstack *stack_a_cpy, tstack *stack_b,tstack *stack_b_cpy);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif