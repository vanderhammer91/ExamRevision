/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <unistd.h>
#include <stdio.h>

//converts the base from an ascii character to an int
int 	base(int mychar, int str_base)
{
	char *str1 = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int	i = 0;

	while (i < str_base)
	{
		if (mychar == str1[i] || mychar == str2[i])
			return (i);
		i++;
	}
	return (-1);
}


int	ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;
	int i = 0;

	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		result = (result * str_base) + base(str[i], str_base);
		i++;
	}
	return (result * sign);
}

/*
int main(int argc, char **argv)
{
	char c = '\n';
	if (argc >= 2)
		printf("atoi result: %d\n", ft_atoi_base(argv[1], 12));
	write(1,&c,1);
	return (0);
}
*/
