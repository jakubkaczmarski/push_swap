/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:52:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 19:03:58 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeAll(tstack *stack_a,
				tstack *stack_a_cpy,
				tstack *stack_b,
				tstack *stack_b_cpy,
				tstack *cpy_stack_a_arr)
{
	free(stack_a_cpy);
	free(stack_a);
	free(stack_b);
	free(stack_b_cpy);
	free(cpy_stack_a_arr);
}

int		main(int argc, char **argv)
{
	tstack	*stack_a;
	tstack	*stack_b;
	tstack	*stack_b_cpy;
	tstack	*cpy_stack_a;
	tstack	*cpy_stack_a_arr;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = createstack(argc);
	cpy_stack_a = createstack(argc);
	cpy_stack_a_arr = createstack(argc);
	stack_b_cpy = createstack(argc);
	stack_b = createstack(argc);
	i = argc - 1;
	while (i > 0)
	{
		if (check_input(argv[i], &stack_a) == 1)
		{
			freeAll(stack_a, cpy_stack_a, stack_b, stack_b_cpy, cpy_stack_a_arr);
			return (0);
		}
		i--;
	}
	if (check_for_duplicates(&stack_a) == 1)
	{
		freeAll(stack_a, cpy_stack_a, stack_b, stack_b_cpy, cpy_stack_a_arr);
		return (0);
	}
	cpy_stack_a_arr = cpy_stack(stack_a, cpy_stack_a_arr);
	cpy_stack_a = cpy_stack(stack_a, cpy_stack_a);
	indexedarr(cpy_stack_a_arr);
	change_arr_values(&stack_a, &cpy_stack_a, cpy_stack_a_arr);
	if (issorted(cpy_stack_a) == 1)
	{
		freeAll(stack_a, cpy_stack_a, stack_b, stack_b_cpy, cpy_stack_a_arr);
		return (0);
	}
	if (stack_a->top + 1 <= 5)
	{
		if (stack_a->top + 1 == 2)
		{
			sort_small_arr_2(&cpy_stack_a, &stack_a);
		}
		else if (stack_a->top + 1 == 3)
		{
			sort_small_arr_3(&cpy_stack_a, &stack_a);
		}
		else if (stack_a->top + 1 == 4)
		{
			sort_small_arr_4(&cpy_stack_a, &stack_a, &stack_b, &stack_b_cpy);
		}
		else if (stack_a->top + 1 == 5)
		{
			sort_small_arr_5(&cpy_stack_a, &stack_a, &stack_b, &stack_b_cpy);
		}
	}
	else
	{
		radix_sort(&cpy_stack_a, &stack_a, &stack_b, &stack_b_cpy);
	}
	// printStack(stack_a);
	freeAll(stack_a, cpy_stack_a, stack_b, stack_b_cpy, cpy_stack_a_arr);
}