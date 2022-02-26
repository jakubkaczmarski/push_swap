/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:32:53 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/26 17:39:16 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

tstack *cpy_stack(tstack *stack_a, tstack *cpy_stack_a)
{
    int i = 0;
    while(i < stack_a->top + 1)
    {
        push(cpy_stack_a ,stack_a->array[i]);
        i++;
    }
    return cpy_stack_a;
}
//Change values of a cpy_array to indexes of numbers
void change_arr_values(tstack** stack_a_copy, tstack* sorted_cpy)
{
    int index = 0;
    int j = 0;
    while(index < sorted_cpy->top + 1)
    {
        j = 0;
        while(j < stack_a_copy[0]->top + 1)
        {
            if(sorted_cpy->array[index] == stack_a_copy[0]->array[j])
            {
                stack_a_copy[0]->array[j] = index;
                break;
            }
            j++;
        }
        index++;
    }
}
void indexedarr(tstack *stack_cpy)
{
    int i = 0;
    int temp = 0;
    int j = 0;
    while(i < stack_cpy->top + 1)
    {
        j = i + 1;
        while(j < stack_cpy->top + 1)
        {
            if(stack_cpy->array[i] > stack_cpy->array[j])
            {
                temp = stack_cpy->array[i];
                stack_cpy->array[i] = stack_cpy->array[j];
                stack_cpy->array[j] = temp;
            }
            j++;
        }
        i++;
    }
}
int issorted(tstack *stack)
{
    int i = 0;
    while(i < stack->top)
    {
        if(stack->array[i] < stack->array[i + 1])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int issorted_desc(tstack *stack)
{
    int i = 0;
    while(i < stack->top)
    {
        if(stack->array[i] > stack->array[i + 1])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void sort_small_arr_2(tstack **stack_sorted, tstack **actual_stack)
{

    if(stack_sorted[0]->array[0] < stack_sorted[0]->array[1])
    {
        ft_printf("sa\n");
        sa(stack_sorted[0]);
        sa(actual_stack[0]);    
    }
        
}
void sort_small_arr_3(tstack **stack_sorted, tstack **actual_stack)
{

    if(stack_sorted[0]->array[2] < stack_sorted[0]->array[1] && stack_sorted[0]->array[1] > stack_sorted[0]->array[0] && stack_sorted[0]->array[2] > stack_sorted[0]->array[0])
    {
        ft_printf("rra\n");
        rra(stack_sorted[0]);
        rra(actual_stack[0]);
    }
    else if(stack_sorted[0]->array[2] > stack_sorted[0]->array[1] && stack_sorted[0]->array[1] > stack_sorted[0]->array[0])
    {
        ft_printf("sa\n");
        sa(stack_sorted[0]);
        sa(actual_stack[0]);
        ft_printf("rra\n");
        rra(stack_sorted[0]);
        rra(actual_stack[0]);
    }
    else if(stack_sorted[0]->array[2] < stack_sorted[0]->array[1] && stack_sorted[0]->array[1] > stack_sorted[0]->array[0] && stack_sorted[0]->array[2] < stack_sorted[0]->array[0])
    {
        ft_printf("sa\n");
        sa(stack_sorted[0]);
        sa(actual_stack[0]);
        ft_printf("ra\n");
        ra(stack_sorted[0]);
        ra(actual_stack[0]);
    }
    else if(stack_sorted[0]->array[2] > stack_sorted[0]->array[1] && stack_sorted[0]->array[1] < stack_sorted[0]->array[0] && stack_sorted[0]->array[0] < stack_sorted[0]->array[2])
    {
        ft_printf("ra\n");
        ra(stack_sorted[0]);
        ra(actual_stack[0]);
    }else if(stack_sorted[0]->array[2] < stack_sorted[0]->array[1] && stack_sorted[0]->array[1] > stack_sorted[0]->array[0])
    {
        ft_printf("rra\n");
        rra(stack_sorted[0]);
        rra(actual_stack[0]);
        ft_printf("rra\n");
        rra(stack_sorted[0]);
        rra(actual_stack[0]);
    }else if(stack_sorted[0]->array[2] > stack_sorted[0]->array[1] && stack_sorted[0]->array[1] < stack_sorted[0]->array[0] && stack_sorted[0]->array[0] > stack_sorted[0]->array[2])
    {
        ft_printf("sa\n");
        sa(stack_sorted[0]);
        sa(actual_stack[0]);
    }
    // printStack(actual_stack[0]);
}
//0 1 2 3 4 5
// 5 2 3 1 4
void rotate_till_value_at_top(tstack **stack_sorted, tstack **actual_stack, int val)
{
    // printStack(stack_sorted[0]);
    // ft_printf("%d \n", stack_sorted[0]->array[0]);
    if (val == stack_sorted[0]->array[0])
    {
        ft_printf("rra\n");
        rra(stack_sorted[0]);
        rra(actual_stack[0]);
        
    }else
    {
        while(stack_sorted[0]->array[stack_sorted[0]->top] != val)
        {
            ft_printf("ra\n");
            ra(stack_sorted[0]);
            ra(actual_stack[0]);
        }
    }
   

}
void sort_small_arr_5(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b_cpy, tstack **stack_b)
{
    // printStack(stack_sorted[0]);
    // if(issorted_desc(stack_sorted[0]) == 1)
    // {
    //     ft_printf("rra\n");
    //     rra(stack_sorted[0]);
    //     rra(actual_stack[0]);
    //     ft_printf("pb\n");
    //     pb(stack_sorted[0], stack_b_cpy[0]);
    //     pb(actual_stack[0], stack_b[0]);
    //     ft_printf("rra\n");
    //     rra(stack_sorted[0]);
    //     rra(actual_stack[0]);
    //     ft_printf("pb\n");
    //     pb(stack_sorted[0], stack_b_cpy[0]);
    //     pb(actual_stack[0], stack_b[0]);
    //     sort_small_arr_3(stack_sorted, actual_stack);
    //     ft_printf("pa\n");
    //     ft_printf("pa\n");
    //     pa(stack_sorted[0], stack_b_cpy[0]);
    //     pa(actual_stack[0], stack_b[0]);
    //     pa(stack_sorted[0], stack_b_cpy[0]);
    //     pa(actual_stack[0], stack_b[0]);
    //     return ;
    // }
    //-71 -306 -645 -775 -961
    rotate_till_value_at_top(stack_sorted,actual_stack, 0);
    // printStack(actual_stack[0]);
    ft_printf("pb\n");
    pb(stack_sorted[0], stack_b_cpy[0]);
    pb(actual_stack[0], stack_b[0]);
    rotate_till_value_at_top(stack_sorted,actual_stack, 1);
    ft_printf("pb\n");
    pb(stack_sorted[0], stack_b_cpy[0]);
    pb(actual_stack[0], stack_b[0]);
    sort_small_arr_3(stack_sorted, actual_stack);
  
    ft_printf("pa\n");
    ft_printf("pa\n");
    pa(stack_sorted[0], stack_b_cpy[0]);
    pa(actual_stack[0], stack_b[0]);
    pa(stack_sorted[0], stack_b_cpy[0]);
    pa(actual_stack[0], stack_b[0]);
        //   printStack(actual_stack[0]);
    //     ft_printf("Top : %d \n",actual_stack[0]->array[actual_stack[0]->top]);
}
void sort_small_arr_4(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b_cpy, tstack **stack_b)
{
    rotate_till_value_at_top(stack_sorted,actual_stack, 0);
    ft_printf("pb\n");
    pb(stack_sorted[0], stack_b_cpy[0]);
    pb(actual_stack[0], stack_b[0]);
    sort_small_arr_3(stack_sorted, actual_stack);
    ft_printf("pa\n");
    pa(stack_sorted[0], stack_b_cpy[0]);
    pa(actual_stack[0], stack_b[0]);
}
void radix_sort(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b, tstack **stack_b_cpy)
{
    int size = stack_sorted[0]->top;
    int i = 0;
    int j = 0;
    int instructions = 0;
    while(issorted(stack_sorted[0]) == 0)
    {
        j = 0;
        while(j < size + 1)
        {
            int num = peek(stack_sorted[0]);
            if(((num >> i)&1))
            {
                instructions++;
                ft_printf("ra\n");
                ra(stack_sorted[0]);
                ra(actual_stack[0]);
            }
            else{
                instructions++;
                ft_printf("pb\n");
                pb(stack_sorted[0], stack_b_cpy[0]);
                pb(actual_stack[0], stack_b[0]);
            }
            j++;
        }
        while(isEmpty(stack_b_cpy[0]) == 0)
        {
            instructions++;
            ft_printf("pa\n");
            pa(stack_sorted[0], stack_b_cpy[0]);
            pa(actual_stack[0], stack_b[0]);
        }
        i++;
    }
    // ft_printf("\n%d\n", instructions);
}

















