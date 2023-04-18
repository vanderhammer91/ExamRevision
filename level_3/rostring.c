/*Assignment name  : rostring
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
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	int i = 0;
	int first_len = 0;
	int	first_index;
	while (str[i])
	{
		if (first_len == 0)
		{
			if ((!is_space(str[i]) && is_space(str[i-1])) || (!is_space(str[i]) && (i == 0)))
			{
				first_index = i;
				while (str[i] && !is_space(str[i]))
				{
					i++;
					first_len++;
				}
			}
		}
		else
		{
			if (!is_space(str[i]) && is_space(str[(i-1)]))
			{
				while (str[i] && !is_space(str[i]))
				{
					ft_putchar(str[i]);
					i++;
				}
				ft_putchar(' ');
			}
		}
		i++;
	}
	i = 0;
	while (first_len--)
	{
		ft_putchar(str[first_index + i]);
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
