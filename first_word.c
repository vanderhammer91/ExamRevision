/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:06:59 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 14:18:59 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
	{
		return (1);
	}
	return (0);
}

void first_word(char *str)
{
	int has_print;

	has_print = 0;
	while (*str)
	{
		if(has_print && is_space(*str))
		{
			ft_putchar('\n');
			return ;
		}
		else if (!is_space(*str))
		{ 
			ft_putchar(*str);
			has_print = 1;
		}
		str++;
	}
	ft_putchar('\n');
}

int main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
