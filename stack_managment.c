/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:35:52 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/02 14:58:08 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*createstack(unsigned int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return (stack);
}

void	indexedarr(t_stack *stack_cpy)
{
	int	i;
	int	temp;
	int	j;

	i = 0;
	temp = 0;
	j = 0;
	while (i < (int)stack_cpy->capacity - 2)
	{
		j = 0;
		while (j < (int)stack_cpy->capacity - 2 - i)
		{
			if (stack_cpy->array[j] > stack_cpy->array[j + 1])
			{
				temp = stack_cpy->array[j + 1];
				stack_cpy->array[j + 1] = stack_cpy->array[j];
				stack_cpy->array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	issorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] < stack->array[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	issorted_desc(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] > stack->array[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
