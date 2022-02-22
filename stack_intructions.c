#include "push_swap.h"
tstack * createStack(unsigned capacity)
{
    tstack* stack = (tstack*)malloc(sizeof(tstack));
    stack->capacity = capacity;
    stack->top = - 1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return (stack);
}
int isFull(tstack* stack)
{
    return (stack->top == (int)stack->capacity - 1);
}
int isEmpty(tstack* stack)
{
    return stack->top == -1;
}
int pop(tstack* stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
void push(tstack* stack, int topush)
{
    if(isFull(stack))
        return ;
    stack->array[++stack->top] = topush;
}
int peek(tstack* stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}
void printStack(tstack* stack)
{
    if(isEmpty(stack))
        return ;
    int i = stack->top;
    while(i != -1)
    {
        ft_printf("%d\n",stack->array[i]);
        i--;
    }
}