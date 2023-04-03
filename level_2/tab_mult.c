/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that 
fits in an int, and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/
#include <unistd.h>

int ft_atoi(char *str)
{
	int result = 0;
	while(*str)
	{
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}	
}

void	tab_mult(int n)
{
	int i = 1;
	char c;
	while (i < 10)
	{
		c = i + '0';
		ft_putchar(c);	
		ft_putstr(" x ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr(i * n);
		ft_putchar('\n');
		i++;	
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(ft_atoi(argv[1]));
	else
		ft_putchar('\n');
	return (0);
}
