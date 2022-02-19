#include "push_swap.h"

int getStackSize(struct sStack *stack)
{
    int i = 0;
    while(stack->array[i])
    {
        i++;
    }
    return i;
};
//Help me god 101
int sort_small_stack(struct sStack *stack)
{
    int size = getStackSize(stack);
    if(size == 3)
    {
    //
        if(stack->array[0] > stack->array[1])
            swaptwofirsttwoitemtop(stack);
        if(stack->array[1] > stack->array[2])
            {}// swa  
           }
    return size;
}
//1 2 3
//2 1 3
//3 2 1
int a_is_sorted(struct sStack *stack)
{
    int i = 0;
    while(stack->array[i + 1])
    {
        if(stack->array[i] < stack->array[i + 1])
        {
            return 0;
        }
        i++;
    }
    return 1;
}