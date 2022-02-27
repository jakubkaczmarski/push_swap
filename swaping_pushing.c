/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping_pushing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:33:18 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:36:03 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int i)
{
	int	temp;

	temp = 0;
	if (isempty(stack) || stack->top == 0)
		return ;
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int i)
{
	int	temp;

	temp = 0;
	if (isempty(stack) || stack->top == 0)
		return ;
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b, int i)
{
	if (isempty(b))
		return ;
	push(a, pop(b));
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int i)
{
	if (isempty(a))
		return ;
	push(b, pop(a));
	if (i == 1)
		write(1, "pb\n", 3);
}
