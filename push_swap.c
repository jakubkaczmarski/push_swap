/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:20:27 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/01/18 14:50:08 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(1,"-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
struct sStack createStack(unsigned capacity)
{
    struct sStack* stack = (struct sStack*)malloc(sizeof(struct sStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    /* data */
    return *stack;
};
// void swapElemement(struct sStack* src, struct sStack* dest)
// {
//     if()
// }

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
static void sortstack(struct sStack *stack, struct sStack *temp)
{
    int first = 1;
    int el;
    while(!isEmpty(stack))
    {
        if(first == 1)
        {
            push(temp, pop(stack));
            first = 0;
            continue;
        }
        el = pop(stack);
        if(!isEmpty(temp) && peek(stack) < peek(temp))
        {
            transferoneeltotheother(stack, temp);
            printf("pa\n");
        }else if(peek(stack) > peek(temp)){
            transferoneeltotheother(temp, stack);
            printf("pb\n");
        }
        
        while(!isEmpty(temp) && peek(temp) > peek(stack))
        {
            transferoneeltotheother(stack, temp);
            printf("pa\n");
        }
        transferoneeltotheother(temp, stack);
        printf("pb\n");
    }
    printStack(*temp);
}
//Goal for today7 Sort this thingy PLZ :)
int main(int argc, char **argv)
{
    struct sStack stack = createStack(argc);
    struct sStack stack2 = createStack(argc);
    int numStack[argc];
    int i = argc - 1;
    int j = 0;
    if(argc == 1)
    {
        printf("Error\n");
        return 0;
    }
    while(i != 0)
    {
        push(&stack, atoi(argv[i]));
        i--;
        j++;
    }
    sortstack(&stack, &stack2);

    // printStack(stack);
    // // rotatestack(&stack);
    // // rotatestack(&stack);
    // // rotatestack(&stack);
    // swaptwofirsttwoitemtop(&stack);
    // printf("sa\n");
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("pb pb pb\n");
    // transferoneeltotheother(&stack2, &stack);
    // transferoneeltotheother(&stack2, &stack);
    // transferoneeltotheother(&stack2, &stack);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("ra rb (rr)\n");
    // rotatestack(&stack);
    // rotatestack(&stack2);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("rra rrb (rrr)\n");
    // reverserotatestack(&stack2);
    // reverserotatestack(&stack);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("sa\n");
    // swaptwofirsttwoitemtop(&stack);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("pa pa pa \n");
    // transferoneeltotheother(&stack, &stack2);
    // transferoneeltotheother(&stack, &stack2);
    // transferoneeltotheother(&stack, &stack2);
    // printStack(stack);
    // printf("B");
    // printStack(stack2);
    // j = 0;
}
