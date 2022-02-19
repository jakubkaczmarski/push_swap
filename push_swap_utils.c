/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:44:35 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/19 18:52:15 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isFull(struct sStack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct sStack* stack)
{
    return stack->top == -1;
};
void push(struct sStack* stack, int item)
{
    if(isFull(stack))
        return ;
    stack->array[++stack->top] = item;
    // write(1,"Pushed\n",8);
};
int pop(struct sStack* stack)
{
        if(isEmpty(stack))
            return -1;
        return stack->array[stack->top--];
};
int peek(struct sStack* stack)
{
    if(isEmpty(stack))
        return -321;
    return stack->array[stack->top];
}
void printStack(struct sStack stack)
{
    while (!isEmpty(&stack))
    {
        ft_putnbr_fd(pop(&stack), 1);
        write(1," ",1);
    }
    write(1,"\n",1);
}

void indexArr(struct sStack *cpyofstack)
{
    int i = 0;
    int min = 0;
    int index = 0;
    int lastIndex = 0;
    int j = 0;
    int size = getStackSize(cpyofstack);
    int arr[size];
    min = cpyofstack->array[i];
    while(i < size - 1)
    {
        if(cpyofstack->array[i] < min && )
        {
            min = cpyofstack->array[i];
            lastIndex = i;
        }
        i++;
    }
    cpyofstack->array[lastIndex] = min;
    arr[j] = min;
    printf("%d Siemanko", min);
}
void sort_big_stack(struct sStack *stack, struct sStack *temp)
{
    struct sStack cpyofStack;
    cpyofStack = *stack;
    indexArr(&cpyofStack);
    
}
void sort_stack(struct sStack *stack, struct sStack *temp)
{
    if(getStackSize(stack) <= 5)
    {
        sort_small_stack(stack);
    }else{
        sort_big_stack(stack, temp);
    }
}