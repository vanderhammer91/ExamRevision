/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')	
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int is_prime(int n)
{
	int i;

	i = 2;
	while (i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}


void add_prime_sum(int n)
{
	int i;
	int result;

	i = 2;
	result = 0;
	while (i <= n)
	{
		if (is_prime(i))
			result += i;
		i++;
	}
	ft_putnbr(result);
}


int	main(int argc, char **argv)
{
	if (argc != 2 || (ft_atoi(argv[1]) < 0))
	{
		ft_putstr("0\n");
		exit(1);
	}
	add_prime_sum(atoi(argv[1]));
	ft_putchar('\n');
	return (0);
}
