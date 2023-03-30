/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
---------------------------------------------------------------

Write a program that takes a string as a parameter, and prints
its words in reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, 
or the begin/end of the string.

If the number of parameters is different from 1, the program 
will display '\n'.

In the parameters that are going to be tested, there won't be 
any "additional" 
spaces (meaning that there won't be additionnal spaces at the
 beginning or at 
the end of the string, and words will always be separated by 
exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't
 it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	rev_wstr(char *str)
{	
	int i;
	int j;

	if (!str)
		return ;
	while(is_space(*str))
		str++;
	i = ft_strlen(str) - 1;
	while(i >= 0)
	{
		while(is_space(str[i]) && (i > 0))
			i--;
		while (i > 0 && !is_space(str[i]) && !is_space(str[i-1]))
			i--;
		if (!is_space(str[i]) && (i > 0))
		{
			j = 0;
			while(!is_space(str[i + j]))
			{
				ft_putchar(str[i+j]);
				j++;
				if ((i + j) > (ft_strlen(str) - 1))
					break ;
			}
			ft_putchar(' ');
			i--;
		}
		if(!is_space(str[i]) && i == 0)
		{
			j = 0;
			while (!is_space(str[i + j]))
			{
				ft_putchar(str[i+j]);
				j++;
				if(i + j > (ft_strlen(str) - 1))
					break;
			}
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
