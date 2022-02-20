#include "push_swap.h"

static int ft_isdigit(int c){
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
static int	ft_strcmp(const char *s1, const char *s2)
{
    unsigned    int			counter;
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