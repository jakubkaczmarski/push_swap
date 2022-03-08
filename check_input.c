/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:49:46 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/08 17:38:59 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char *str, t_stack **stack_a)
{
	int	num;

	num = ft_atoi(str);
	if (check_for_int_overflow(num, str) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
	{
		push(stack_a[0], num);
		return (0);
	}
}

int	check_for_duplicates(t_stack **stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a[0]->top + 1)
	{
		j = i + 1;
		while (j < stack_a[0]->top + 1)
		{
			if (stack_a[0]->array[i] == stack_a[0]->array[j])
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	rotate_till_value_at_top(t_stack **stack_sorted,
								t_stack **actual_stack,
								int val)
{
	if (val == stack_sorted[0]->array[0])
	{
		rra(stack_sorted[0], 0);
		rra(actual_stack[0], 1);
	}
	else
	{
		while (stack_sorted[0]->array[stack_sorted[0]->top] != val)
		{
			ra(stack_sorted[0], 0);
			ra(actual_stack[0], 1);
		}
	}
}

void	change_arr_values(t_stack **input_stack,
						t_stack **stack_a_copy,
						t_stack *sorted_cpy)
{
	int	index;
	int	j;

	index = 0;
	while (index < (int)stack_a_copy[0]->capacity - 1)
	{
		j = 0;
		while (j < (int)stack_a_copy[0]->capacity - 1)
		{
			if (input_stack[0]->array[index] == sorted_cpy->array[j])
			{
				stack_a_copy[0]->array[index] = j;
			}
			j++;
		}
		index++;
	}
}
