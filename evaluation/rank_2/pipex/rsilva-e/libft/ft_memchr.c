/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:02:23 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/17 23:02:23 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	chr;
	size_t			i;

	i = 0;
	string = (unsigned char *) str;
	chr = (unsigned char) c;
	while (i < n)
	{
		if (string [i] == chr)
		{
			return ((char *) string + i);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char str[] = "12243 55563644";
	char *ptr = ft_memchr(str,'\0',4);
	printf("str: %s\n", str);
	printf("str: %s\n", ptr);
	return(0);
}*/