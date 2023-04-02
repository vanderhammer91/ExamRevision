/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	int	first_len = 0;
	int	i = 0;
	int printed;

	while(str[i])
	{
		while(is_space(str[i]))
			i++;
		if (!is_space(str[i]) && first_len == 0)
		{
			while(!is_space(str[i]) && str[i])
			{
				first_len++;
				i++;
			}
		}
		else if(!is_space(str[i]))
		{
			printed = 0;
			while(!is_space(str[i]) && str[i])
			{
				printed = 1;
				ft_putchar(str[i]);
				i++;
			}
			if(printed)
				ft_putchar(' ');
		}
	}
	i = 0;
	while(is_space(str[i]))
		i++;
	while(first_len--)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);
	ft_putchar('\n');
	return (0);
}
