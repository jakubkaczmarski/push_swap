#include "push_swap.h"

int main(int argc, char **argv)
{
    if(argc < 2)
        return 0;
    tstack *stack_a;
    tstack *stack_b;
    tstack *stack_b_cpy;
    tstack *cpy_stack_a;
    tstack *cpy_stack_a_arr;
    stack_a = createStack(argc);
    cpy_stack_a = createStack(argc);
    cpy_stack_a_arr = createStack(argc);
    stack_b_cpy = createStack(argc);
    stack_b = createStack(argc);
    int i = argc - 1;
    while(i > 0)
    {
        if(check_input(argv[i], &stack_a) == 1)
        {
            return 0;
        }
        i--;
    }

    if(check_for_duplicates(&stack_a) == 1)
        return 0;
    cpy_stack_a_arr = cpy_stack(stack_a, cpy_stack_a_arr);
    cpy_stack_a = cpy_stack(stack_a, cpy_stack_a);
    indexedarr(cpy_stack_a_arr);
    //Change values in an cpy_arr
    change_arr_values(&cpy_stack_a,cpy_stack_a_arr);
    radix_sort(&cpy_stack_a, &stack_a, &stack_b, &stack_b_cpy);
    // printStack(stack_a);
    // ft_printf("\n");
    // printStack(stack_a);
}