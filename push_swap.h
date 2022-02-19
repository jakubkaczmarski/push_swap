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
int a_is_sorted(struct sStack *stack);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void printStack(struct sStack stack);
char	*ft_itoa(int n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int getStackSize(struct sStack *stack);
void sort_stack(struct sStack *stack, struct sStack *temp);
int sort_small_stack(struct sStack *stack);