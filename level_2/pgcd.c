/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		printf("%d", n % 10);
	}
	else if (n < 10)
		printf("%d", n);
}

void	pgcd(int n1, int n2)
{
	int hcd = n1;
	if (n2 < n1)
		hcd = n2;
	while (hcd > 1)
	{
		if (n1 % hcd == 0 && n2 % hcd == 0)
		{
			ft_putnbr(hcd);
			return ;
		}
		hcd--;
	}
	ft_putnbr(hcd);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
