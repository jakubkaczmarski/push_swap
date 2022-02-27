/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:52:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:30:40 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	freeall(tstack *stack_a,
				tstack *stack_a_cpy,
				tstack *stack_b,
				tstack *stack_b_cpy)
{
	free(stack_a_cpy);
	free(stack_a);
	free(stack_b);
	free(stack_b_cpy);
	return (0);
}

void	initialize_arr(tstack **stack_cpy, tstack **stack_a)
{
	tstack	*stack_arr;

	stack_cpy[0] = cpy_stack(stack_a[0], stack_cpy[0]);
	stack_arr = createstack(stack_cpy[0]->capacity);
	stack_arr = cpy_stack(stack_cpy[0], stack_arr);
	indexedarr(stack_arr);
	change_arr_values(stack_a, stack_cpy, stack_arr);
	free(stack_arr);
}

void	runthesort(tstack **stack_a,
						tstack **cpy_stack_a,
						tstack **stack_b_cpy,
						tstack **stack_b)
{
	if (stack_a[0]->top + 1 <= 5)
	{
		if (stack_a[0]->top + 1 == 2)
			sort_small_arr_2(cpy_stack_a, stack_a);
		else if (stack_a[0]->top + 1 == 3)
			sort_small_arr_3(cpy_stack_a, stack_a);
		else if (stack_a[0]->top + 1 == 4)
			sort_small_arr_4(cpy_stack_a, stack_a, stack_b, stack_b_cpy);
		else if (stack_a[0]->top + 1 == 5)
			sort_small_arr_5(cpy_stack_a, stack_a, stack_b, stack_b_cpy);
	}
	else
		radix_sort(cpy_stack_a, stack_a, stack_b, stack_b_cpy);
}

int	main(int argc, char **argv)
{
	tstack	*stack_a;
	tstack	*stack_b;
	tstack	*stack_b_cpy;
	tstack	*cpy_stack_a;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = createstack(argc);
	cpy_stack_a = createstack(argc);
	stack_b_cpy = createstack(argc);
	stack_b = createstack(argc);
	i = argc - 1;
	while (i > 0)
	{
		if (check_input(argv[i], &stack_a) == 1)
			return (freeall(stack_a, cpy_stack_a, stack_b, stack_b_cpy));
		i--;
	}
	if (check_for_duplicates(&stack_a) == 1 || issorted(stack_a) == 1)
		return (freeall(stack_a, cpy_stack_a, stack_b, stack_b_cpy));
	initialize_arr(&cpy_stack_a, &stack_a);
	runthesort(&stack_a, &cpy_stack_a, &stack_b, &stack_b_cpy);
	freeall(stack_a, cpy_stack_a, stack_b, stack_b_cpy);
}
