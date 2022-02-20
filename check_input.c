#include "push_swap.h"
int check_input(char *str, tstack **stack_a)
{
    int num = ft_atoi(str);
    if(check_for_int_overflow(num, str) == 0)
    {
        ft_printf("Error\n");
        return 1;
    }
    else{
        push(stack_a[0], num);
        return 0;
    }
}
int check_for_duplicates(tstack **stack_a)
{
    int i = 0;
    int j = 0;
    while(i < stack_a[0]->top + 1)
    {
        j = i + 1;
        while(j < stack_a[0]->top + 1)
        {
            if(stack_a[0]->array[i] == stack_a[0]->array[j])
            {
                ft_printf("Error\n");
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}