/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:52:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/02 14:34:52 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	freeall(t_stack *stack_a,
				t_stack *stack_a_cpy,
				t_stack *stack_b,
				t_stack *stack_b_cpy)
{
	free(stack_a_cpy);
	free(stack_a);
	free(stack_b);
	free(stack_b_cpy);
	free(stack_a_cpy->array);
	free(stack_a->array);
	free(stack_b_cpy->array);
	free(stack_b->array);
	return (0);
}

void	initialize_arr(t_stack **stack_cpy, t_stack **stack_a)
{
	t_stack	*stack_arr;

	stack_cpy[0] = cpy_stack(stack_a[0], stack_cpy[0]);
	stack_arr = createstack(stack_cpy[0]->capacity);
	stack_arr = cpy_stack(stack_cpy[0], stack_arr);
	indexedarr(stack_arr);
	change_arr_values(stack_a, stack_cpy, stack_arr);
	free(stack_arr->array);
	free(stack_arr);
}

void	runthesort(t_stack **stack_a,
						t_stack **cpy_stack_a,
						t_stack **stack_b_cpy,
						t_stack **stack_b)
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
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_b_cpy;
	t_stack	*cpy_stack_a;
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
