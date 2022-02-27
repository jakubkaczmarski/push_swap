/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_intructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:53:51 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 19:37:05 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isfull(tstack *stack)
{
	return (stack->top == (int)stack->capacity - 1);
}

int	isempty(tstack *stack)
{
	return (stack->top == -1);
}

int	pop(tstack *stack)
{
	if (isempty(stack))
		return (-1);
	return (stack->array[stack->top--]);
}

void	push(tstack *stack, int topush)
{
	if (isfull(stack))
		return ;
	stack->array[++stack->top] = topush;
}

int	peek(tstack *stack)
{
	if (isempty(stack))
		return (-1);
	return (stack->array[stack->top]);
}
