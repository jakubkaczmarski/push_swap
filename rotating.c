/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:27:31 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:35:52 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int num)
{
	int	temp;
	int	j;
	int	i;

	temp = 0;
	j = a->top;
	if (isempty(a) || a->top == 0)
		return ;
	i = a->top - 1;
	temp = a->array[a->top];
	while (j > 0)
	{
		a->array[j--] = a->array[i--];
	}
	a->array[0] = temp;
	if (num == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *a, int num)
{
	int	temp;
	int	j;
	int	i;

	temp = 0;
	j = a->top;
	if (isempty(a) || a->top == 0)
		return ;
	i = a->top - 1;
	temp = a->array[a->top];
	while (j > 0)
	{
		a->array[j--] = a->array[i--];
	}
	a->array[0] = temp;
	if (num == 1)
		write(1, "rb\n", 3);
}

void	rra(t_stack *a, int num)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = 0;
	j = 1;
	if (isempty(a) || a->top == 0)
		return ;
	temp = a->array[0];
	while (i != a->top)
	{
		a->array[i++] = a->array[j++];
	}
	a->array[a->top] = temp;
	if (num == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *a, int num)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = 0;
	j = 1;
	if (isempty(a) || a->top == 0)
		return ;
	temp = a->array[0];
	while (i != a->top)
	{
		a->array[i++] = a->array[j++];
	}
	a->array[a->top] = temp;
	if (num == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rrr\n", 5);
}
