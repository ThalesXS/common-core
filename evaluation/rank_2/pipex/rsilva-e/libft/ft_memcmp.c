/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:46:18 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/17 15:46:18 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = str1;
	p2 = str2;
	i = 0;
	while ((i < n) && *p1 == *p2)
	{
		p1++;
		p2++;
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	else
	{
		return (*p1 - *p2);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	size_t x;
	x = 4;
	char str[] = "A234";
	char str1[] = "A1234";
	char str2[] = "Adf2345";
	char str3[] = "A12345";
	
	
	printf("ft_memcmp: %d\n",ft_memcmp(str,str1,x));
	printf("ft_memcmp: %d\n",ft_memcmp(str1,str2,x));
	printf("ft_memcmp:%d\n",ft_memcmp(str2, str3,x));

	return(0);

}*/