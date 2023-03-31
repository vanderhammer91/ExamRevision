/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
-----------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of 
elements in the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
#include <stdio.h>

int	max(int	*tab, unsigned int len)
{
	int		result;
	unsigned int	i;
	if (!tab)
		return (0);
	i = 0;
	result = tab[i];
	while(i < len)
	{
		if (tab[i] > result)
			result = tab[i];
		i++;
	}
	return (result);
}

/*
int	main(void)
{
	int 	my_ints[] = { 1, 2, 3, 4, 17, 1 };
	int 	my_len = 6;
	int	my_result = max(my_ints, my_len);
	
	printf("result: %d \n", my_result);
	return (0);
}
*/
