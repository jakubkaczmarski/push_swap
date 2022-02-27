/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:32:53 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 19:50:52 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_arr_2(tstack **stack_sorted, tstack **actual_stack)
{
	if (stack_sorted[0]->array[0] < stack_sorted[0]->array[1])
	{
		sa(stack_sorted[0], 0);
		sa(actual_stack[0], 1);
	}
}

void	sort_small_arr_3(tstack **stack_sorted, tstack **actual_stack)
{
	if (stack_sorted[0]->array[2] < stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0]
		&& stack_sorted[0]->array[2] > stack_sorted[0]->array[0])
	{
		rra(stack_sorted[0], 0);
		rra(actual_stack[0], 1);
	}
	else if (stack_sorted[0]->array[2] > stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0])
	{
		sa(stack_sorted[0], 0);
		sa(actual_stack[0], 1);
		rra(stack_sorted[0], 0);
		rra(actual_stack[0], 1);
	}
	else if (stack_sorted[0]->array[2] < stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0]
		&& stack_sorted[0]->array[2] < stack_sorted[0]->array[0])
	{
		sa(stack_sorted[0], 0);
		sa(actual_stack[0], 1);
		ra(stack_sorted[0], 0);
		ra(actual_stack[0], 1);
	}
	else if (stack_sorted[0]->array[2] > stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] < stack_sorted[0]->array[0]
		&& stack_sorted[0]->array[0] < stack_sorted[0]->array[2])
	{
		ra(stack_sorted[0], 0);
		ra(actual_stack[0], 1);
	}
	else if (stack_sorted[0]->array[2] < stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] > stack_sorted[0]->array[0])
	{
		rra(stack_sorted[0], 0);
		rra(actual_stack[0], 1);
		rra(stack_sorted[0], 0);
		rra(actual_stack[0], 1);
	}
	else if (stack_sorted[0]->array[2] > stack_sorted[0]->array[1]
		&& stack_sorted[0]->array[1] < stack_sorted[0]->array[0]
		&& stack_sorted[0]->array[0] > stack_sorted[0]->array[2])
	{
		sa(stack_sorted[0], 0);
		sa(actual_stack[0], 1);
	}
}

void	sort_small_arr_5(tstack **stack_sorted,
						tstack **actual_stack,
						tstack **stack_b_cpy,
						tstack **stack_b)
{
	rotate_till_value_at_top(stack_sorted, actual_stack, 0);
	pb(stack_sorted[0], stack_b_cpy[0], 0);
	pb(actual_stack[0], stack_b[0], 1);
	rotate_till_value_at_top(stack_sorted, actual_stack, 1);
	pb(stack_sorted[0], stack_b_cpy[0], 0);
	pb(actual_stack[0], stack_b[0], 1);
	sort_small_arr_3(stack_sorted, actual_stack);
	pa(stack_sorted[0], stack_b_cpy[0], 0);
	pa(actual_stack[0], stack_b[0], 1);
	pa(stack_sorted[0], stack_b_cpy[0], 0);
	pa(actual_stack[0], stack_b[0], 1);
}

void	sort_small_arr_4(tstack **stack_sorted,
						tstack **actual_stack,
						tstack **stack_b_cpy,
						tstack **stack_b)
{
	rotate_till_value_at_top(stack_sorted, actual_stack, 0);
	pb(stack_sorted[0], stack_b_cpy[0], 0);
	pb(actual_stack[0], stack_b[0], 1);
	sort_small_arr_3(stack_sorted, actual_stack);
	pa(stack_sorted[0], stack_b_cpy[0], 0);
	pa(actual_stack[0], stack_b[0], 1);
}

void	radix_sort(tstack **stack_sorted,
				tstack **actual_stack,
				tstack **stack_b,
				tstack **stack_b_cpy)
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
			{
				ra(stack_sorted[0], 0);
				ra(actual_stack[0], 1);
			}
			else
			{
				pb(stack_sorted[0], stack_b_cpy[0], 0);
				pb(actual_stack[0], stack_b[0], 1);
			}
			j++;
		}
		while (isempty(stack_b_cpy[0]) == 0)
		{
			pa(stack_sorted[0], stack_b_cpy[0], 0);
			pa(actual_stack[0], stack_b[0], 1);
		}
		i++;
	}
}
