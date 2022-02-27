/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_intructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:53:51 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:35:59 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isfull(t_stack *stack)
{
	return (stack->top == (int)stack->capacity - 1);
}

int	isempty(t_stack *stack)
{
	return (stack->top == -1);
}

int	pop(t_stack *stack)
{
	if (isempty(stack))
		return (-1);
	return (stack->array[stack->top--]);
}

void	push(t_stack *stack, int topush)
{
	if (isfull(stack))
		return ;
	stack->array[++stack->top] = topush;
}

int	peek(t_stack *stack)
{
	if (isempty(stack))
		return (-1);
	return (stack->array[stack->top]);
}
