/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:05:15 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/13 11:05:15 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char	*p;

	p = ptr;
	while (n != 0)
	{
		*p = (unsigned char) x ;
		p++;
		n--;
	}
	return (ptr);
}
/*
#include <string.h>

int main()
{
	char str[] = "Hello     mundo";
	char str1[] = "42 porto     ricardo";
	
	printf(" Antes da funçao : %s\n",str);
	ft_memset(str,'R',5);
	printf(" Depois da funçao : %s\n",str);
	
	printf(" Antes da funçao : %s\n",str);
	ft_memset(str+5,48,5);
	printf(" Depois da funçao : %s\n",str);
	
	printf(" Antes da funçao : %s\n",str1);
	memset(str1,48,5);
	printf(" Depois da funçao : %s\n",str1);
}*/
