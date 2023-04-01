/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:39:35 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 15:08:11 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	*array_out;
	int arr_len;
	int	i;
	
	if (end > start)
	{
		arr_len = end - start + 1;
		array_out = (int *)malloc(sizeof(int) * arr_len);
		if (!array_out)
			return (NULL);
		i = 0;
		while (i < arr_len)
		{
			array_out[i] = start + i;
			i++;
		}
	}
	else
	{
		arr_len = start - end + 1;
		array_out = (int *)malloc(sizeof(int) * arr_len);
		if (!array_out)
			return (NULL);
		i = 0;
		while (i < arr_len)
		{
			array_out[i] = start - i;
			i++;
		}
	}
	return (array_out);
}
/*
int main(void)
{
	int	my_start;
	int	my_end;
	int	*my_result;
	int i;

	my_start = 0;
	my_end = -3;
	printf("start: %d, end: %d \n", my_start, my_end);
	printf("result :\n");
	my_result = ft_range(my_start, my_end);
	i = 0;
	while (i < 4)
	{
		printf("my_result[%d]: %d\n", i, my_result[i]);
		i++;
	}
	return (0);
}
*/
