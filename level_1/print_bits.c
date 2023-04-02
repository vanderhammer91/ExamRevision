/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"%
*/
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	unsigned char	bit;
	char		c;

	i = 7;
	while(i >= 0)
	{
		bit = (octet >> i) & 1;
		c = bit + '0';
		write(1, &c, 1);
		i--;
	}
}

/*
int	main(void)
{
	print_bits(10);
	return (0);
}
*/
