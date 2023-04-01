/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:12:25 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/28 12:33:22 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_overwrite(char *str, char to_write)
{	
	while (*str)
	{
		if (*str == to_write)
		{
			*str = '-';
		}
		str++;
	}
}

void	inter(char **argv)
{
	char	*first;
	char	*second;
	int		i;
	int		j;

	if(!argv[1] || !argv[2])
		return ;
		
	first = argv[1];
	second = argv[2];
	i = 0;
	while (first[i] != '\0')
	{
		j = 0;
		while (second[j] != '\0')
		{
			if(first[i] == second[j])
			{
				ft_putchar(first[i]);
				ft_overwrite(second, first[i]);
			}		
			j++;
		}
		i ++;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		inter(argv);
	ft_putchar('\n');
	return (0);
}

