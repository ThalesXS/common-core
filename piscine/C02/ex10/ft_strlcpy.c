/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:31:39 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/31 16:35:43 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	src_len;

	if (!dst || !src)
		return (0);
	count = 0;
	src_len = ft_strlen(src);
	while (count < size - 1 && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (src_len);
}
/*
#include<stdio.h>
int	main(void)
{
	char	dest[15];
	char	src[] = {"0dcbsidwhiu"};
	unsigned int	size;

	size = ft_strlcpy(dest, src, 10);
	printf("src = %s\ndest = %s\nsize = %i", src, dest, size);
	return (0);
}
*/
