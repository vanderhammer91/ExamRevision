/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:54:21 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/24 13:16:30 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : do_op
Expected files   : do_op.c
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	do_add(char **argv)
{
	int var1 = atoi(argv[1]);
	int var2 = atoi(argv[3]);
	int result = var1 + var2;
	printf("%d\n", result);
}

void	do_sub(char **argv)
{
	int var1 = atoi(argv[1]);
	int var2 = atoi(argv[3]);
	int result = var1 - var2;
	printf("%d\n", result);
}

void	do_mult(char **argv)
{
	int var1 = atoi(argv[1]);
	int var2 = atoi(argv[3]);
	int result = var1 * var2;
	printf("%d\n", result);
}

void	do_div(char **argv)
{
	int var1 = atoi(argv[1]);
	int var2 = atoi(argv[3]);
	int result = var1 / var2;
	printf("%d\n", result);
}

void	do_mod(char **argv)
{
	int var1 = atoi(argv[1]);
	int var2 = atoi(argv[3]);
	int result = var1 % var2;
	printf("%d\n", result);
}

void	do_op(char **argv)
{
	if (argv[2][0] == '+')
		do_add(argv);
	if (argv[2][0] == '-')
		do_sub(argv);
	if (argv[2][0] == '*')
		do_mult(argv);
	if (argv[2][0] == '/')
		do_div(argv);
	if (argv[2][0] == '%')
		do_mod(argv);
}

int	main(int argc, char ** argv)
{
	if (argc != 1)
		do_op(argv);
	else
		ft_putchar('\n');

	return (0);
}
