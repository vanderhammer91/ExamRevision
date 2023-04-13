/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010
*/

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		i;
	unsigned char	reverse = 0;

/*
	reverse |= (octet & 1) << 7;
	reverse |= (octet & 2) << 5;
	reverse |= (octet & 4) << 3;
	reverse |= (octet & 8) << 1;
	reverse |= (octet & 16) >> 1;
	reverse |= (octet & 32) >> 3;
	reverse |= (octet & 64) >> 5;
	reverse |= (octet & 128) >> 7;
	return (reverse);
	// i = 0; 0000 1010 >> 7 
	// octet: 0000 0000
	// rever: 0101 0000
	//
	*/
	i = 0;
	while(i <= 3)
	{
		reverse |= (octet & (1 << i)) << (7 - 2*i);
		reverse |= (octet & (16 << i)) >> (1 + 2*i);
		i++;
	}

	return (reverse);
}

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
	unsigned char c;
	print_bits(0b00001111);
	write(1, "\n", 1);
	c = reverse_bits(0b00001111);
	print_bits(c);
	return (0);
}
*/
