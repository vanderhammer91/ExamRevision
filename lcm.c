/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:23:43 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/24 14:57:30 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/
#include <stdlib.h>
#include <stdio.h>

unsigned int	hcm(unsigned int a, unsigned int b)
{
	unsigned int hcf;
	unsigned int i;

	if (!a || !b)
	{
		return (0);
	}
	hcf = 1;
	i = 2;
	while (i <= a && i <= b)
	{
		if (a % i == 0 && b % i == 0)
			hcf = i;		
		i++;
	}
	return (hcf);
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int hcf;
	unsigned long m_product;

	if (!a || !b || (int)a <= 0 || (int)b <= 0) 
		return (0);
	if (a == b)
		return (a);
	hcf = hcm(a,b);
	if (!hcf)
		return (0);
	m_product = a * b;
	return (unsigned int)(m_product / hcf);
}

/*
int	main(void)
{
	unsigned int var1 = -1;
	unsigned int var2 = 2932;
	unsigned int result = lcm(var1, var2);
	printf("highest common factor: %d \n", hcm(var1, var2));
	printf("var 1: %d, var2: %d, result: %d \n", var1, var2, result);
	return (0);
}
*/
