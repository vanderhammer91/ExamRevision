/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int clearleft(char *str, int index)
{
	int i = 0;
	while (i < index)
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}
void	rev_wstr(char *str)
{
	int i = ft_strlen(str);
	int j;

	while(i--)
	{
		if (!is_space(str[i]) && is_space(str[(i-1)]))
		{
			j = i;
			while (!is_space(str[j]) && str[j])
			{
				ft_putchar(str[j]);
				j++;
			}
			if (!clearleft(str, i))
				ft_putchar(' ');
		}
		else if (!is_space(str[i]) && i == 0)
		{
			j = i;
			while (!is_space(str[j]) && str[j])
			{
				ft_putchar(str[j]);
				j++;
			}
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
