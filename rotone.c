/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
----------------------------------------------------------------------

Write a program that takes a string and displays it, replacing 
each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours 
tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	rotone(char *str)
{
	while (*str)
	{
		if (*str == 'z')
			ft_putchar('a');
		else if(*str == 'Z')
			ft_putchar('A');
		else if(is_alpha(*str))
			ft_putchar(*str + 1);
		else
			ft_putchar(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}	
