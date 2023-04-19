/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:
*/
#include <stdio.h>
#include <stdlib.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int get_wordcount(char *str)
{
	int count = 0;
	int i = 0;
	while (str[i])
	{
		if (!is_space(str[i]) && i == 0)
			count++;
		if (!is_space(str[i]) && is_space(str[(i-1)]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strndup(char *str, int len)
{
	char *out = (char *)malloc(sizeof(char) * (len + 1));
	int i = 0;
	while (str[i] && i < len)
	{
		out[i] = str[i];
		i++;
	}
	while(i <= len)
	{
		out[i] = 0;
		i++;
	}
	return (out);
}


char    **ft_split(char *str)
{
	char **split;
	if (!str)
		return (NULL);
	int word_count = get_wordcount(str); 
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	int i = 0;
	int j = 0;
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
	char *mystring = "this is a test. testing! six!  3";
	int result1 = get_wordcount(mystring);
	printf("word count is: %d\n", result1);

	char **my_split = ft_split(mystring);
	
	//printf("%s\n", my_split[0]);
	int i = 0;
	while(my_split[i])
	{
		printf("string %d: %s\n", i, my_split[i]);
		i++;
	}
	return (0);
}*/
