/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:41:41 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 18:57:07 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	ulstr(char *str)
{
	while (*str)
	{
		if (is_upper(*str))
		{
			*str = (*str + 32);
		}
		else if(is_lower(*str))
		{
			*str = (*str - 32);
		}
		ft_putchar(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != 0)
	{
		ulstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
