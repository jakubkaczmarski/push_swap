/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:52:58 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/03/08 15:58:53 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	sa_rra_op(t_stack *stack_a, t_stack *stack_a_cpy)
{
	sa_operation(stack_a, stack_a_cpy);
	rra_operation(stack_a, stack_a_cpy);
}

void	sa_ra_op(t_stack *stack_a, t_stack *stack_a_cpy)
{
	sa_operation(stack_a, stack_a_cpy);
	ra_operation(stack_a, stack_a_cpy);
}

void	double_rra_op(t_stack *stack_a, t_stack *stack_a_c)
{
	rra(stack_a_c, 0);
	rra(stack_a, 1);
	rra(stack_a_c, 0);
	rra(stack_a, 1);
}
