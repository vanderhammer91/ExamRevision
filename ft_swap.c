/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:07:26 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/25 16:18:59 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);

*/
#include <stdio.h>
#include <string.h>

void	ft_swap(int *a, int *b)
{
	int temp;
	
	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int main(void)
{
	int a = 12;
	int b = 5;
	int	*a_pt = &a;
	int	*b_pt = &b;

	printf("pre operation: a: %d, b: %d \n", *a_pt, *b_pt);
	ft_swap(a_pt, b_pt);
	printf("pre operation: a: %d, b: %d \n", *a_pt, *b_pt);
	return (0);
}
*/
