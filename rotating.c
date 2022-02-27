/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:27:31 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 18:52:33 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(tstack *a, int num)
{
	int	temp;
	int	j;
	int	i;

	temp = 0;
	j = a->top;
	if (isEmpty(a) || a->top == 0)
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
void	rb(tstack *a, int num)
{
	int	temp;
	int	j;
	int	i;

	temp = 0;
	j = a->top;
	if (isEmpty(a) || a->top == 0)
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
void	rr(tstack *a, tstack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
void	rra(tstack *a, int num)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = 0;
	j = 1;
	if (isEmpty(a) || a->top == 0)
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
void	rrb(tstack *a, int num)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = 0;
	j = 1;
	if (isEmpty(a) || a->top == 0)
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
void	rrr(tstack *a, tstack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rrr\n", 5);
}
