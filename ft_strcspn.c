/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:21:18 by ivanderw          #+#    #+#             */
/*   Updated: 2023/03/26 14:38:17 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);% 

DESCRIPTION
     The strspn() function spans the initial part of the null-terminated string s
     as long as the characters from s occur in the null-terminated string charset.
     In other words, it computes the string array index of the first character of s
     which is not in charset, else the index of the first null character.

     The strcspn() function spans the initial part of the null-terminated string s
     as long as the characters from s do not occur in the null-terminated string
     charset (it spans the complement of charset).  In other words, it computes the
     string array index of the first character of s which is also in charset, else
     the index of the first null character.

RETURN VALUES
     The strspn() and strcspn() functions return the number of characters spanned.
*/
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	count;
	char 	*pt1;
	char 	*pt2;

	count = 0;
	pt1 = (char *)s;
	while (*pt1 != '\0')
	{
		pt2 = (char *)reject;
		while (*pt2 != '\0')
		{
			if (*pt1 == *pt2)
			{
				return (count);
			}
			pt2++;
		}
		count++;
		pt1++;
	}
	return (count);
}
/*
int main(void)
{
    const char *s1 = "hello";
    const char *r1 = "aeiou";
    size_t result1 = ft_strcspn(s1, r1);
    size_t expected1 = strcspn(s1, r1);
    printf("Test case 1:\n");
    printf("Input string: '%s'\n", s1);
    printf("Reject string: '%s'\n", r1);
    printf("Expected result: %zu\n", expected1);
    printf("Actual result: %zu\n", result1);
    printf("\n");

    const char *s2 = "12345";
    const char *r2 = "abcd";
    size_t result2 = ft_strcspn(s2, r2);
    size_t expected2 = strcspn(s2, r2);
    printf("Test case 2:\n");
    printf("Input string: '%s'\n", s2);
    printf("Reject string: '%s'\n", r2);
    printf("Expected result: %zu\n", expected2);
    printf("Actual result: %zu\n", result2);
    printf("\n");

    const char *s3 = "this is a test";
    const char *r3 = "t";
    size_t result3 = ft_strcspn(s3, r3);
    size_t expected3 = strcspn(s3, r3);
    printf("Test case 3:\n");
    printf("Input string: '%s'\n", s3);
    printf("Reject string: '%s'\n", r3);
    printf("Expected result: %zu\n", expected3);
    printf("Actual result: %zu\n", result3);
    printf("\n");

    return 0;
}
*/
