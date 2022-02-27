/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:35:52 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 19:45:55 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(tstack *stack)
{
	int	i;

	if (isempty(stack))
		return ;
	i = stack->top;
	while (i != -1)
	{
		ft_printf("%d\n", stack->array[i]);
		i--;
	}
}

tstack	*createstack(unsigned int capacity)
{
	tstack	*stack;

	stack = (tstack *)malloc(sizeof(tstack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return (stack);
}

void	indexedarr(tstack *stack_cpy)
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

int	issorted(tstack *stack)
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

int	issorted_desc(tstack *stack)
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
