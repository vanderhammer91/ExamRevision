/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:15:51 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/24 12:52:13 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
 */
#include <unistd.h>

void ft_putchar(char c)
{
	write (1, &c, 1);
}

int	is_caps(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void rot_13(char *str)
{
	while (*str)
	{
		if (is_alpha(*str))
		{
			if	(is_caps(*str))
			{
				if ((*str + 13) > 'Z')
					ft_putchar(*str - 13);
				else
					ft_putchar(*str + 13);
			}
			else
			{
				if ((*str + 13) > 'z')
					ft_putchar(*str - 13);
				else
					ft_putchar(*str + 13);
			}
		}
		else
			ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int	main(int argc, char	**argv)
{
	if (argc == 2)
		rot_13(argv[1]);	
	else
		ft_putchar('\n');
	return (0);
}
