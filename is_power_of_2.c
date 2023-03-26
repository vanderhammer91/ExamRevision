/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:59:13 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 19:07:40 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/
#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n <= 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 != 0)
			return (0);
		n = n/2;
	}
	return (1);
}

/*
int	main(void)
{
	unsigned int test1 = -1;
	unsigned int test2 = 0;
	unsigned int test3 = 1;

	int result1;
	int result2;
	int result3;

	result1 = is_power_of_2(test1);
	result2 = is_power_of_2(test2);
	result3 = is_power_of_2(test3);

	printf("test 1: %d, result: %d \n", test1, result1);
	printf("test 2: %d, result: %d \n", test2, result2);
	printf("test 3: %d, result: %d \n", test3, result3);

	return (0);
}
*/
