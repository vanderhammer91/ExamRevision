/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:38:12 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 20:45:48 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : fprime
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
$
*/
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_prime(int n)
{
	int i;

	if(n <= 1)
		return (0);
	else if(n == 2)
		return (1);
	else
	{
		i = 2;
		while (i < n)
		{
			if (n % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char put;
	
	if(n == 0)
	{
		ft_putchar('0');
	}
	else if (n < 10)
	{
		put = n + '0';
		ft_putchar(put);
	}
	else
	{
		ft_putnbr (n/10);
		put = n % 10 + '0';
		ft_putchar(put);
	}
}

void	fprime(int n)
{
	int i;
	int writ;
	int init;

	init = n;
	if (n < 1)
		return ;
	if (n == 1 || n == 2)
	{
		ft_putchar('1');
		return ;
	}
	i = 2;
	writ = 0;	
	while(i < n)
	{
		if(is_prime(i))
		{
			if (n % i == 0)
			{
				while (n % i == 0)
				{
					n = n / i;
					ft_putnbr(i);
					ft_putchar('*');
					writ = 1;
				}
			}
		}
		i++;
	}
	if(writ == 1)
	{
		ft_putnbr(n);
	}
	else if (is_prime(init))
		ft_putnbr(init);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		fprime(atoi(argv[1]));	
	}
	ft_putchar('\n');
	return (0);
}
