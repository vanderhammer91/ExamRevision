/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/
#include <stdio.h>
#include <stdlib.h>

int	get_length(int nbr)
{
	int count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}


char	*ft_itoa(int nbr)
{
	char  	*arr;
	int	i;
	int	nbr_len;

	nbr_len = get_length(nbr);
	if (!nbr_len)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!arr)
		return (NULL);
	arr[nbr_len] = '\0';
	if (nbr < 0)
	{
		nbr = - nbr;
		arr[0] = '-';
	}
	if (nbr == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	i = nbr_len - 1;
	while (nbr > 0)
	{
		arr[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (arr);
}


/*
int	main(void)
{
	char	*result;	
	int 	input;
	//int	result1;

	input = 123456789;
	
	result = ft_itoa(input);
	if (!result)
		return (0);
	//result1 = get_length(input);
	printf("inputted int: %d \n", input);
	//printf("length of the inputted int: %d \n", result1);
	printf("inputted int as an array: %s \n", result);

	return (0);
}
*/
