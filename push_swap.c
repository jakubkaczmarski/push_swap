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
    // printStack(cpy_stack_a_arr);
    //  printStack(cpy_stack_a);
    // printStack(cpy_stack_a_arr);
    
    change_arr_values(&stack_a,&cpy_stack_a,cpy_stack_a_arr);
//    printStack(cpy_stack_a);
//    printStack(cpy_stack_a_arr);
    // printStack(cpy_stack_a);
    //  printStack(cpy_stack_a);
    if(issorted(cpy_stack_a) == 1)
        return 0;
    // Sort
    if(stack_a->top + 1 <= 5)
    {
        if(stack_a->top + 1 == 2)
        {
            sort_small_arr_2(&cpy_stack_a, &stack_a);
        }else if(stack_a->top + 1 == 3)
        {
            sort_small_arr_3(&cpy_stack_a, &stack_a);
        }else if(stack_a->top + 1 == 4)
        {
            sort_small_arr_4(&cpy_stack_a, &stack_a, &stack_b, &stack_b_cpy);
        }
        else if(stack_a->top + 1 == 5)
        {
            sort_small_arr_5(&cpy_stack_a, &stack_a, &stack_b, &stack_b_cpy);
        }
    }else{
        radix_sort(&cpy_stack_a, &stack_a, &stack_b, &stack_b_cpy);
    }
    
    free(cpy_stack_a);
    free(stack_a);
    free(stack_b);
    free(stack_b_cpy);
   
    // ft_printf("\n");
}