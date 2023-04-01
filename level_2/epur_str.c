/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:53:18 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/25 18:30:41 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_delim(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

size_t get_epur_length(char *str)
{
	size_t	count;
	int	prev_is_space;

	prev_is_space = 0;
	count = 0;
	while (*str && is_delim(*str))
		str++;
	while (*str)
	{
		if (is_delim(*str) && !prev_is_space)
		{
			prev_is_space = 1;
			str++;	
			count++;
		}
		else if(is_delim(*str) && prev_is_space)
		{
			str++;
		}
		else
		{
			prev_is_space = 0;
			count++;
			str++;
		}
	}
	str--;
	while (is_delim(*str))
	{
		str--;
		count--;
	}			
	return (count);
}


void	epur_str(char *str)
{
	size_t 	epur_len;
	size_t	i;
	int	prev_is_space;

	epur_len = get_epur_length(str);
	if (!epur_len)
	{
		ft_putchar('\n');
		return ;
	}
	while (*str && is_delim(*str))
		str++;

	i = 0;
	prev_is_space = 0;
	while(*str && i < epur_len)
	{
		if (is_delim(*str) && !prev_is_space)
		{
			prev_is_space = 1;
			ft_putchar(*str);
			i++;
			str++;	
		}
		else if(is_delim(*str) && prev_is_space)
		{
			str++;
		}
		else if(!is_delim(*str))
		{
			prev_is_space = 0;
			ft_putchar(*str);	
			i++;
			str++;
		}		
	}
	ft_putchar('\n');
}

int main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	else
		ft_putchar('\n');	
	return (0);
}
