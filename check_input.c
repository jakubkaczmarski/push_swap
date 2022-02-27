/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:49:46 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 18:57:42 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char *str, tstack **stack_a)
{
	int	num;

	num = ft_atoi(str);
	if (check_for_int_overflow(num, str) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
	{
		push(stack_a[0], num);
		return (0);
	}
}

int	check_for_duplicates(tstack **stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a[0]->top + 1)
	{
		j = i + 1;
		while (j < stack_a[0]->top + 1)
		{
			if (stack_a[0]->array[i] == stack_a[0]->array[j])
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
