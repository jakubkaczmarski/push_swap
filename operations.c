/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:37:03 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/27 21:38:51 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_operation(t_stack *stack_a, t_stack *stack_a_cpy)
{
	rra(stack_a_cpy, 0);
	rra(stack_a, 1);
}

void	sa_operation(t_stack *stack_a, t_stack *stack_a_cpy)
{
	sa(stack_a_cpy, 0);
	sa(stack_a, 1);
}

void	ra_operation(t_stack *stack_a, t_stack *stack_a_cpy)
{
	ra(stack_a_cpy, 0);
	ra(stack_a, 1);
}

void	pa_op(t_stack *stack_a, t_stack *stack_b,
			t_stack *stack_a_c, t_stack *bcpy)
{
	pa(stack_a_c, bcpy, 0);
	pa(stack_a, stack_b, 1);
}

void	pb_op(t_stack *stack_a, t_stack *stack_b,
			t_stack *stack_a_c, t_stack *bcpy)
{
	pb(stack_a_c, bcpy, 0);
	pb(stack_a, stack_b, 1);
}
