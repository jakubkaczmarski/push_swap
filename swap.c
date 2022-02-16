#include "push_swap.h"

void swaptwofirsttwoitemtop(struct sStack* stack) {
    int topone = pop(stack);
    int down = pop(stack);
    push(stack, topone);
    push(stack, down);
}

void transferoneeltotheother(struct sStack* stack, struct sStack* src) {
    if (isEmpty(src))
        return;
    int toput;
    toput = pop(src);
    push(stack, toput);
}

void reverserotatestack(struct sStack* stack) {
    //last element is the starting element
    //So first to pop becomes the last to be pushed
    //all the others don't change
    int size = stack->capacity;
    int *arr = malloc(sizeof(int) * (size + 1));
    int i;
    i = 1;
    if(!arr)
        return ;
    while(!isEmpty(stack))
    {
        arr[i++] = pop(stack);
    }
    i--;
    arr[0] = arr[i];
    i--;
    while(i > -1)
    {
        push(stack,arr[i--]);
    }
}

void rotatestack(struct sStack* stack) {
    int size = stack->capacity;
    int *num = malloc(sizeof(int) * (size + 1));
    if(!num)
        return ;
    int i = 0;
    int counter = 0;
    int temp;
    while(!isEmpty(stack))
        num[i++] = pop(stack); 
    size = i;
    counter = i;
    num[counter] = num[0];
    i = 1;
    while(size != 0)
    {
        // printf("Exec");
        push(stack, num[size--]);
    }
    //4 3 2 1
    //3 2 1 4
    free(num);
}
