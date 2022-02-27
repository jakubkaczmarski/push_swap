/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:32:54 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:38:25 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct sStack
{
	int				top;
	unsigned int	capacity;
	int				*array;
}				t_stack;

t_stack			*createstack(unsigned int capacity);
int				isfull(t_stack *stack);
int				isempty(t_stack *stack);
int				pop(t_stack *stack);
void			push(t_stack *stack, int topush);
int				peek(t_stack *stack);
void			print_stack(t_stack *stack);
void			sa(t_stack *stack, int i);
void			sa_rra_op(t_stack *stack_a, t_stack *stack_a_cpy);
void			sb(t_stack *stack, int i);
void			ss(t_stack *a, t_stack *b);
void			sa_operation(t_stack *stack, t_stack *stack_cpy);
void			pa(t_stack *a, t_stack *b, int i);
void			pa_op(t_stack *stack_a, t_stack *stack_b,
					t_stack *stack_a_cpy, t_stack *bcpy);
void			pb_op(t_stack *stack_a, t_stack *stack_b,
					t_stack *stack_a_cpy, t_stack *bcpy);
void			pb(t_stack *a, t_stack *b, int i);
void			ra(t_stack *a, int num);
void			rb(t_stack *b, int num);
void			rr(t_stack *a, t_stack *b);
void			ra_operation(t_stack *stack_a, t_stack *stack_a_cpy);
void			rra(t_stack *a, int num);
void			rrb(t_stack *a, int num);
void			rrr(t_stack *a, t_stack *b);
void			double_rra_op(t_stack *stack_a, t_stack *stack_a_cpy);
void			rra_operation(t_stack *stack_a, t_stack *stack_a_cpy);
int				check_for_int_overflow(int num, char *str);
int				check_input(char *str, t_stack **stack_a);
int				check_for_duplicates(t_stack **stack_a);
t_stack			*cpy_stack(t_stack *stack_a, t_stack *cpy_stack_a);
void			change_arr_values(t_stack **input_stack,
					t_stack **stack_a_copy,
					t_stack *sorted_cpy);
void			radix_sort(t_stack **stack_sorted,
					t_stack **actual_stack,
					t_stack **stack_b,
					t_stack **stack_b_cpy);
void			sort_small_arr_3(t_stack **stack_sorted,
					t_stack **actual_stack);
void			sort_small_arr_2(t_stack **stack_sorted,
					t_stack **actual_stack);
void			sort_small_arr_4(t_stack **stack_sorted,
					t_stack **actual_stack,
					t_stack **stack_b_cpy,
					t_stack **stack_b);
void			sort_small_arr_5(t_stack **stack_sorted,
					t_stack **actual_stack,
					t_stack **stack_b_cpy,
					t_stack **stack_b);
void			rotate_till_value_at_top(t_stack **stack_sorted,
					t_stack **actual_stack,
					int val);
int				issorted(t_stack *stack);
int				issorted_desc(t_stack *stack);
void			indexedarr(t_stack *stack_cpy);
int				freeall(t_stack *stack_a,
					t_stack *stack_a_cpy,
					t_stack *stack_b,
					t_stack *stack_b_cpy);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

#endif