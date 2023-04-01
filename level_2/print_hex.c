/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
----------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}


void	print_hex(int my_int)
{
	char	*hex_digits = "0123456789abcdef";
	int 	mod;
	if (my_int >= 16)
		print_hex(my_int / 16);
	mod = my_int % 16;
	ft_putchar(hex_digits[mod]);
}


int main(int argc, char **argv)
{
	int my_int;
	if (argc == 2)
	{
		my_int = ft_atoi(argv[1]);		
		if (my_int < 0)
		{
			ft_putchar('-');
			my_int = -my_int;		
		}
		print_hex(my_int);
	}
	ft_putchar('\n');
	return (0);
}
