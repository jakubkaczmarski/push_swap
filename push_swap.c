#include "push_swap.h"

int main(int argc, char **argv)
{
    if(argc < 2)
        return 0;
    tstack *stack_a;
    stack_a = createStack(argc);
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
    indexedarr(stack_a);
    printStack(stack_a);
}