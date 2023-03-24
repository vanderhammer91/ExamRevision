/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:39 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/23 17:05:30 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

size_t ft_get_camel_length(char *str)
{
	size_t count;

	count = 0;
	while (*str)
	{
		if (is_uppercase(*str))
		{
			count++;
		}
		count ++;
		str++;
	}
	return (count);
}

char	to_lower(char c)
{
	return (c + 32);
}

void camel_to_snake(char *str)
{
	char *newstring;
	size_t new_len;

	new_len = ft_get_camel_length(str);
	if (!new_len)
	{
		ft_putchar('\n');
		return ;
	}
	newstring = malloc(sizeof(char) * (new_len + 1));
	if (!newstring)
		return ;

	while(*str)
	{
		if(is_uppercase(*str))
		{
			ft_putchar('_');
			ft_putchar(to_lower(*str));
		}
		else
			ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int main(int argc, char	**argv)
{
	if(argc == 2)
	{
		camel_to_snake(argv[1]);
	}
	else
	{
		ft_putchar('\n');
	}
	return (0);
}
