/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:27:31 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/22 00:24:54 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(tstack* a)
{
    int temp = 0;
    int j = a->top;
    int i; 
    if(isEmpty(a) || a->top == 0)
        return ;
    i = a->top - 1;
    temp = a->array[a->top];
    while(j > 0)
    {
        a->array[j--] = a->array[i--];
    }
    a->array[0] = temp;
}
void rb(tstack* a)
{
    int temp = 0;
    int j = a->top;
    int i; 
    if(isEmpty(a) || a->top == 0)
        return ;
    i = a->top - 1;
    temp = a->array[a->top];
    while(j > 0)
    {
        a->array[j--] = a->array[i--];
    }
    a->array[0] = temp;
}
void rr(tstack *a, tstack *b)
{
    ra(a);
    rb(b);
}
void rra(tstack* a)
{
    int temp = 0;
    int i = 0;
    int j = 1;
    if(isEmpty(a) || a->top == 0)
        return ;
    temp = a->array[0];
    while(i != a->top)
    {
        a->array[i++] = a->array[j++];
    }
    a->array[a->top] = temp;
}
void rrb(tstack* a)
{
    int temp = 0;
    int i = 0;
    int j = 1;
    if(isEmpty(a) || a->top == 0)
        return ;
    temp = a->array[0];
    while(i != a->top)
    {
        a->array[i++] = a->array[j++];
    }
    a->array[a->top] = temp;
}
void rrr(tstack* a, tstack *b)
{
    ra(a);
    rb(b);
}