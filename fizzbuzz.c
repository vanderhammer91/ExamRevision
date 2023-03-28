/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:52:29 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/27 15:09:42 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	fizzbuzz()
{
	int i;
	char put;
	char mod;
		
	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			ft_putstr("fizzbuzz");
		else if (i % 5 == 0)
			ft_putstr("buzz");
		else if (i % 3 == 0)
			ft_putstr("fizz");
		else
		{
			if (i < 10)
			{
				put = i + '0';
				ft_putchar(put);
			}
			else
			{
				put = i/10 + '0';
				mod = i%10 + '0';
				ft_putchar(put);
				ft_putchar(mod);
			}
		}
		i++;
		ft_putchar('\n');
	}
}

int	main(void)
{
		fizzbuzz();	
	return (0);
}

