/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:10:28 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 19:35:35 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int end_of_string(char *str)
{
	while (*str)
	{
		if (!is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

void expand_str(char *str)
{
	int i;
	char	*pt;

	i = 0;
	while (str[i])
	{
		while (is_space(str[i]))
				i++;
		if (str[i] && !is_space(str[i]))
		{
			while (str[i] && !is_space(str[i]))
			{
				ft_putchar(str[i]);
				i++;
			}
			pt = &str[i];
			if (end_of_string(pt))
				return ;
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putchar(' ');
		}
	}
}


int	main(int argc, char	**argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	ft_putchar('\n');
	return (0);
}


