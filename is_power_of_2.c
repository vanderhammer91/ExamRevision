/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:21:06 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/25 16:51:46 by ivanderw         ###   ########.fr       */
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

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n != 1)
	{
		if (n % 2 != 0)
			return (0);
		n = n / 2;
	}
	return (1);
}

/*
int main() 
{
    unsigned int n1 = 8;
    unsigned int n2 = 10;
    unsigned int n3 = 16;

    printf("%u is a power of 2: %d\n", n1, is_power_of_2(n1));
    printf("%u is a power of 2: %d\n", n2, is_power_of_2(n2));
    printf("%u is a power of 2: %d\n", n3, is_power_of_2(n3));

    return 0;
}
*/
