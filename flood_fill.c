/*
Assignment name  : flood_fill
Expected files   : flood_fill.c
Allowed functions: -
-------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting 
point. Starting from the given 'begin' t_point, this function fills an
entire zone by replacing characters inside with the character 'F'. 

A zone is an group of the same character delimitated horizontally and 
vertically by other characters or the array boundry.

The flood_fill function won't fill diagonally.
The flood_fill function will be prototyped like this:

void  flood_fill(char **tab, t_point size, t_point begin);
*/
#include <stdlib.h>
#include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	int 	i;
	int 	j;
	char 	target;
	t_point	temp;

	temp.x = -1;
	temp.y = -1;
	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			if(i == begin.x && j == begin.y)
			{
				if (!target)
					target = tab[j][i];
				tab[j][i] = 'F';
				if((j - 1) >= 0 && tab[(j - 1)][i] == target)
				{
					temp.x = i;
					temp.y = j - 1;
					flood_fill(tab, size, temp);
				}
				if ((j + 1) < size.y && tab[j + 1][i] == target)
				{
					temp.x = i;
					temp.y = j + 1;
					flood_fill(tab, size, temp);
				}
				if(i - 1 >= 0 && tab[j][i - 1] == target)
				{
					temp.x = i - 1;
					temp.y = j;
					flood_fill(tab, size, temp);
				}
				
				if ((i + 1) < size.x && tab[j][i + 1] == target)
				{
					temp.x = i + 1;
					temp.y = j;
					flood_fill(tab, size, temp);
				}			
			}		
			//ft_putchar(tab[j][i]);
			i++;
		}
		//ft_putchar ('\n');
		j++;
	}
}
