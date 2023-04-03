/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
-------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);


DESCRIPTION
     The strcmp() and strncmp() functions lexicographi-
     cally compare the null-terminated strings s1 and s2.

RETURN VALUES
     The strcmp() and strncmp() functions return an inte-
     ger greater than, equal to, or less than 0, according
     as the string s1 is greater than, equal to, or less
     than the string s2.  The comparison is done using
     unsigned characters, so that `\200' is greater than
     `\0'.
*/

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char *my_s1 = (unsigned char *)s1;
	unsigned char *my_s2 = (unsigned char *)s2;
	while(*my_s1 && *my_s2)
	{
		if(*my_s1 !=  *my_s2)
			return (*my_s1 - *my_s2);
		my_s1++;
		my_s2++;
	}
	if(*my_s1 && !*my_s2)
		return (*my_s1);
	if(!*my_s1 && *my_s2)
		return (*my_s2);
	return (0);
}

/*
int	main(void)
{
	char	*str1 = "hello World";
	char	*str2 = "";
	int 	result = ft_strcmp(str1, str2);
	printf("result : %d \n", result);
}
*/
