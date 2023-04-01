/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

size_t	get_word_count(char	*str)
{
	size_t	i = 0;
	size_t	word_count = 0;

	while (str[i])
	{
		if (i == 0 && !is_space(str[i]))
		{
			word_count++;
			i++;
		}
		else if (i >= 1 && !is_space(str[i]) && is_space(str[(i - 1)]))
		{
			word_count++;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (word_count);
}

char	*ft_strndup(char *str, int n)
{
	char	*mystr;
	int		i;

	mystr = malloc(sizeof(char) * (n + 1));
	if (!mystr)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		mystr[i] = str[i];
		i++;
	}
	while (i <= n)
	{
		mystr[i] = 0;
		i++;
	}
	return (mystr);
}


char	**ft_split(char *str)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	word_count;

	if (!str)
		return (NULL);
	word_count = get_word_count(str);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while(is_space(str[j]))
			j++;
		str = &str[j];
		j = 0;
		while(str[j] && !is_space(str[j]))
			j++;
		split[i] = ft_strndup(str, j);
		i++;
	}
	split[i] = 0;
	return (split);
}

/*
int	main(void)
{
	char mystr[] = "three words apart";
	char **my_spl;
	//printf("%zu \n", get_word_count(mystr));

	my_spl = ft_split(mystr);

	printf("first: %s \n", my_spl[0]);
	printf("second: %s \n", my_spl[1]);
	printf("third: %s \n", my_spl[2]);

	return (0);
}
*/
