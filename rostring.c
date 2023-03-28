/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:09:35 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 17:14:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

<-------------INCOMPLETE FUNCTION --------------------------->

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

*/
#include <unistd.h>


void ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void rostring(char *s)
{
	int	i = 0;
	int	first_word_length = 0;

	while (s[i])
	{
		while (is_space(s[i]))
			i++;
		if (s[i] && !is_space(s[i]))
		{
			if (first_word_length == 0)
			{
				while (s[i] && !is_space(s[i]))
				{
					first_word_length++;
					i++;
				}
			}
			else
			{
				while (s[i] && !is_space(s[i]))
				{
					ft_putchar(s[i]);
					i++;
				}
					ft_putchar(' ');
			}
		}
	}

	i = 0;
	while (is_space(s[i]))
			i++;
	while (first_word_length--)
		write(1, &s[i++], 1);

}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		rostring(argv[1]);
	}
		ft_putchar('\n');
	return (0);
}
