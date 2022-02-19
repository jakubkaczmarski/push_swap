/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:20:27 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:58 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_isdigit(int c){
	return (c >= '0' && c <= '9');
}
int	ft_atoi(const char *str)
{
	int	res;
	int	counter;
	int	negative;

	negative = 1;
	counter = 0;
	while (str[counter] == ' ' || str[counter] == '\t' || str[counter] == '\n'
		|| str[counter] == '\v' || str[counter] == '\f' || str[counter] == '\r')
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			negative = -1;
		counter++;
	}
	res = 0;
	while (str[counter] != '\0' && ft_isdigit(str[counter]))
		res = res * 10 + (str[counter++] - '0');
	return (res * negative);
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(1,"-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
struct sStack createStack(unsigned capacity)
{
    struct sStack* stack = (struct sStack*)malloc(sizeof(struct sStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    /* data */
    return *stack;
};
// void swapElemement(struct sStack* src, struct sStack* dest)
// {
//     if()
// }

int checkforRepetition(struct  sStack *stack, int size)
{
    int i  = 0;
    int j  = 0;
    while(i < size - 1)
    {
        j = i + 1;
        while(j < size)
        {
            if(stack->array[i] == stack->array[j])
            {
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			counter;
	unsigned char	*magic;
	unsigned char	*helpme;

	counter = 0;
	magic = (unsigned char *)s1;
	helpme = (unsigned char *)s2;
	while ((magic[counter] != '\0' || helpme[counter] != '\0'))
	{
		if (magic[counter] != helpme[counter])
		{
			return (magic[counter] - helpme[counter]);
		}
		counter++;
	}
	return (0);
}
int check_for_int_overflow(int num, char *str)
{
    char *str1 = ft_itoa(num);
    if(ft_strcmp(str1, str) == 0)
        return 1;
    else{
        return 0;
    }
}
//Goal for today7 Sort this thingy PLZ :)
int main(int argc, char **argv)
{
    struct sStack stack = createStack(argc);
    struct sStack stack2 = createStack(argc);
    int numStack[argc];
    int i = argc - 1;
    char *str;
    int arr[argc];
    int j = 0;
    if(argc == 1)
    {
        printf("Error\n");
        return 0;
    }
    while(i != 0)
    {
        //check if it's int 
        str = argv[i];
        if(check_for_int_overflow(ft_atoi(argv[i]), str) == 1)
            push(&stack, ft_atoi(argv[i]));
        else{
            printf("Error\n");
            return 0;
        }
        i--;
    }
    if(checkforRepetition(&stack, argc) == 1)
    {
        printf("Repetition in the input\n");
        return 0;
    } 
    if(a_is_sorted(&stack) == 1)
    {
        printf("Sorted");
        return 0;
    }
    sort_stack(&stack, &stack2);
    // sort_small_stack(stack);
    // printStack(stack);
    // // rotatestack(&stack);
    // // rotatestack(&stack);
    // // rotatestack(&stack);
    // swaptwofirsttwoitemtop(&stack);
    // printf("sa\n");
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("pb pb pb\n");
    // transferoneeltotheother(&stack2, &stack);
    // transferoneeltotheother(&stack2, &stack);
    // transferoneeltotheother(&stack2, &stack);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("ra rb (rr)\n");
    // rotatestack(&stack);
    // rotatestack(&stack2);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("rra rrb (rrr)\n");
    // reverserotatestack(&stack2);
    // reverserotatestack(&stack);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("sa\n");
    // swaptwofirsttwoitemtop(&stack);
    // printStack(stack);
    // printf("B\n");
    // printStack(stack2);
    // printf("pa pa pa \n");
    // transferoneeltotheother(&stack, &stack2);
    // transferoneeltotheother(&stack, &stack2);
    // transferoneeltotheother(&stack, &stack2);
    // printStack(stack);
    // printf("B");
    // printStack(stack2);
    // j = 0;
}
