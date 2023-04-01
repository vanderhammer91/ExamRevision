/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	get_index(char c)
{
	if(is_upper(c))
		return (c - 64);
	else if(is_lower(c))
		return (c - 96);
	else
		return (1);
}

void	repeat_alpha(char *str)
{
	int i;
	int j;
	int mult;

	j = 0;
	while (str[j])
	{
		mult = get_index(str[j]);
		i = 0;
		while (i < mult)
		{
			ft_putchar(str[j]);
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	if(argc == 2)
		repeat_alpha(argv[1]);
	ft_putchar('\n');	
	return (0);
}
