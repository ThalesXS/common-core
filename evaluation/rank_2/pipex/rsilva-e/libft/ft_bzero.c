/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:37:56 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/30 16:46:55 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, unsigned int n)
{
	unsigned char	*p;

	p = ptr;
	while (n != 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}
/*
int main(void)
{
	char str[] = "@@@";
	ft_bzero(str,2);
	printf("%s\n",str);
	
	char str1[] = {1,2,45};
	ft_bzero(str1,2);
	printf("%d\n",str1[0]);
	
}*/
