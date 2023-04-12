/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
*/
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int count = 0;
	while (str[count])
		count++;
	return (count);
}

int	hidenp(char *str1, char *str2)
{
	int i;
	int j;
	int str1_len = ft_strlen(str1);
	int str2_len = ft_strlen(str2);
	
	j = 0;
	i = 0;
	while (j < str2_len)
	{
		if(str1[i] == str2[j])
		{
			i++;
		}
		j++;
	}

	if(i == str1_len)
		return (1);
	return (0);
}
	
int main(int argc, char **argv)
{
	if (argc == 3)
		ft_putchar(hidenp(argv[1], argv[2]) + '0');
	ft_putchar('\n');

	return (0);
}
