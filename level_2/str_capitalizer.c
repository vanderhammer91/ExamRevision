/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/
#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	str_capitalizer(char **argv)
{
	char	*temp;
	int		i;

	argv++;
	while (*argv)
	{
		temp = *argv;
		i = 0;
		while (temp[i])
		{	
			if (is_upper(temp[i]))
				temp[i] = temp[i] + 32;
				i++;
		}
		i = 0;
		while (temp[i])
		{
			if (i == 0 && is_lower(temp[i]))
				ft_putchar(temp[i] - 32);
			else if (i > 0 && is_lower(temp[i]) && is_space(temp[i-1]))
				ft_putchar(temp[i] - 32);
			else
				ft_putchar(temp[i]);
			i++;
		}
		ft_putchar('\n');
		argv++;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		str_capitalizer(argv);
	else
		ft_putchar('\n');
	return (0);
}
