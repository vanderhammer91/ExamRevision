/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
-------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).
The strdup() function allocates sufficient memory for a copy 
of the string s1, does the copy, and returns a pointer to it.  
The pointer may subsequently be used as an argument to the 
function free(3).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char	*str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;		
		str++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char 	*out;
	int	i;

	if (!src)
		return (NULL);
	out = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{	
		out[i] = src[i];
		i++;
	}	
	out[i] = '\0';
	return (out);
}

/*
int	main(void)
{
	char 	*new;
	char	*old = "test!";

	new = ft_strdup(old);
	if (!new)
		free(new);
	printf("new string contents: %s \n", new);
	return (0);
}
*/
