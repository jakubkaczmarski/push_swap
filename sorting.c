/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:32:53 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:35:55 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_arr_2(t_stack **stack_sorted, t_stack **actual_stack)
{
	if (stack_sorted[0]->array[0] < stack_sorted[0]->array[1])
	{
		sa_operation(actual_stack[0], stack_sorted[0]);
	}
}

void	sort_small_arr_3(t_stack **stack_sorted, t_stack **actual_stack)
{
	if (stack_sorted[0]->array[2] < stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0]
		&& stack_sorted[0]->array[2] > stack_sorted[0]->array[0])
		rra_operation(actual_stack[0], stack_sorted[0]);
	else if (stack_sorted[0]->array[2] > stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0])
	{
		sa_operation(actual_stack[0], stack_sorted[0]);
		rra_operation(actual_stack[0], stack_sorted[0]);
	}
	else if (stack_sorted[0]->array[2] < stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0]
		&& stack_sorted[0]->array[2] < stack_sorted[0]->array[0])
		sa_rra_op(actual_stack[0], stack_sorted[0]);
	else if (stack_sorted[0]->array[2] > stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] < stack_sorted[0]->array[0]
		&& stack_sorted[0]->array[0] < stack_sorted[0]->array[2])
		ra_operation(actual_stack[0], stack_sorted[0]);
	else if (stack_sorted[0]->array[2] < stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0])
		double_rra_op(actual_stack[0], stack_sorted[0]);
	else
		sa_operation(actual_stack[0], stack_sorted[0]);
}

void	sort_small_arr_5(t_stack **stack_sorted,
						t_stack **actual_stack,
						t_stack **stack_b_cpy,
						t_stack **stack_b)
{
	rotate_till_value_at_top(stack_sorted, actual_stack, 0);
	pb_op(actual_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
	rotate_till_value_at_top(stack_sorted, actual_stack, 1);
	pb_op(actual_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
	sort_small_arr_3(stack_sorted, actual_stack);
	pa_op(actual_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
	pa_op(actual_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
}

void	sort_small_arr_4(t_stack **stack_sorted,
						t_stack **actual_stack,
						t_stack **stack_b_cpy,
						t_stack **stack_b)
{
	rotate_till_value_at_top(stack_sorted, actual_stack, 0);
	pb_op(actual_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
	sort_small_arr_3(stack_sorted, actual_stack);
	pa_op(actual_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
}

void	radix_sort(t_stack **stack_sorted,
				t_stack **ac_stack,
				t_stack **stack_b,
				t_stack **stack_b_cpy)
{
	int	size;
	int	i;
	int	j;
	int	num;

	size = stack_sorted[0]->top;
	i = 0;
	j = 0;
	while (issorted(stack_sorted[0]) == 0)
	{
		j = 0;
		while (j < size + 1)
		{
			num = peek(stack_sorted[0]);
			if (((num >> i) & 1))
				ra_operation(ac_stack[0], stack_sorted[0]);
			else
				pb_op(ac_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
			j++;
		}
		while (isempty(stack_b_cpy[0]) == 0)
			pa_op(ac_stack[0], stack_b[0], stack_sorted[0], stack_b_cpy[0]);
		i++;
	}
}
