/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
---------------------------------------------------------------

Write a program called alpha_mirror that takes a string and
 displays this string
after replacing each alphabetical character by the opposite 
alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_lower(char c)
{
	if(c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	alpha_mirror(char *str)
{
	int diff;
	
	while (*str)
	{
		if(is_lower(*str))
		{
			if (*str >= 'n')
			{
				diff = *str - 'n';
				ft_putchar('m' - diff);
			}
			else
			{
				diff = 'm' - *str;
				ft_putchar ('n' + diff);
			}
		}
		else if(is_upper(*str))
		{
			if (*str >= 'N')
			{
				diff = *str - 'N';
				ft_putchar('M' - diff);
			}
			else
			{
				diff = 'M' - *str;
				ft_putchar ('N' + diff);
			}
		}
		else
			ft_putchar(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	ft_putchar('\n');
	return (0);
}
