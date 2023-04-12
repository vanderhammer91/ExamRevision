/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$	*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t')
		str++;
	if(*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = - sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int ft_isprime(int n)
{
	int i = 2;
	while (i <= (n / 2))
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	fprime(int n)
{

	if(n == 1)
	{
		ft_putchar('0');
		return ;
	}
	else if (n == 2)
	{
		ft_putchar('1');
		return ;
	}
	int i = 2;
	while (i <= n / 2)
	{
		if (ft_isprime(i) && n % i == 0)
		{
			n = n / i;
			ft_putnbr(i);
			ft_putchar('*');
		}
		else
			i++;
	}
	ft_putnbr(n);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int result = ft_atoi(argv[1]);
		if (result > 0)
			fprime(result);
	}
	ft_putchar('\n');
	return (0);
}
