#include "push_swap.h"

int indexedarr(tstack *stack)
{
    int i = 0;
    int temp = 0;
    int j = 0;
    tstack *stack_cpy;
    while(i < stack->top + 1)
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