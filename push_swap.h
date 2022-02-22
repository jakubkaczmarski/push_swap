#include <unistd.h>
#include <stdlib.h>

#include "printf/ft_printf/ft_printf.h"

typedef struct sStack
{
    int top;
    unsigned capacity;
    int *array;
    /* data */
} tstack;

tstack * createStack(unsigned capacity);
//###Stack instructions###
int isFull(tstack* stack);
int isEmpty(tstack* stack);
int pop(tstack* stack);
void push(tstack* stack, int topush);
int peek(tstack* stack);
void printStack(tstack* stack);
//###Push_swap_instructions###
//Swaping
void sa(tstack* stack);
void sb(tstack* stack);
void ss(tstack* a, tstack* b);
//Pushing
void pa(tstack* a, tstack *b);
void pb(tstack* a, tstack *b);
//Rotating
void ra(tstack* a);
void rb(tstack* b);
void rr(tstack* a, tstack *b);
//Reverse rotating
void rra(tstack* a);
void rrb(tstack* a);
void rrr(tstack *a, tstack *b);
//###Input checking###
int check_for_int_overflow(int num, char *str);
int check_input(char *str,tstack **stack_a);
int check_for_duplicates(tstack **stack_a);
//###Sorting Part###//
tstack *cpy_stack(tstack *stack_a, tstack *cpy_stack_a);
void change_arr_values(tstack** stack_a_copy, tstack* sorted_cpy);
void radix_sort(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b, tstack **stack_b_cpy);
void sort_small_arr_3(tstack **stack_sorted, tstack **actual_stack);
void sort_small_arr_2(tstack **stack_sorted, tstack **actual_stack);
void sort_small_arr_5(tstack **stack_sorted, tstack **actual_stack, tstack **stack_b_cpy, tstack **stack_b);
//###Array with Indexes creation ###//
void indexedarr(tstack *stack_cpy);
//###Helper Func###
int	ft_atoi(const char *str);
char	*ft_itoa(int n);
