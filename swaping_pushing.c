#include "push_swap.h"
void sa(tstack* stack)
{
    int temp;
    temp = 0;
    if(isEmpty(stack) || stack->top == 0)
        return ;
    temp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = temp;
}
void sb(tstack* stack)
{
    int temp;
    temp = 0;
    if(isEmpty(stack) || stack->top == 0)
        return ;
    temp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = temp;
}
void ss(tstack* a, tstack* b)
{
    sa(a);
    sb(b);
}
void pa(tstack* a, tstack* b)
{
    if(isEmpty(b))
        return ;
    push(a, pop(b));
}
void pb(tstack* a, tstack* b)
{
    if(isEmpty(a))
        return ;
    push(b, pop(a));
}