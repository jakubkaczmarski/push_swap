#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct sStack
{
    int top; //Top element of stack
    unsigned capacity; //Memory reserved on the stack os basically how much memory does stack take
    int *array; //pointer to our stack which is an int array
};
void reverserotatestack(struct sStack* stack);
void rotatestack(struct sStack* stack);
int isFull(struct sStack* stack);
int isEmpty(struct sStack* stack);
void push(struct sStack* stack, int item);
int pop(struct sStack* stack);
int peek(struct sStack* stack);
void swaptwofirsttwoitemtop(struct sStack *stack);
void transferoneeltotheother(struct sStack *stack,struct sStack *src);