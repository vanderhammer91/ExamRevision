/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

DESCRIPTION
     The stpcpy() and strcpy() functions copy the string src to dst (including
     the terminating `\0' character.)

RETURN VALUES
     The strcpy() and strncpy() functions return dst.
*/
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	char 	*src;
	char	*dest;	
	int	i;	

	src = s2;
	dest = s1;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char 	*src = "test";
	char	dest[5] = "";

	ft_strcpy(dest, src);
	printf("output: %s \n", dest);
	return (0);
}
*/
