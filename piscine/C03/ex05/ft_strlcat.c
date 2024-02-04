/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:14:42 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/01 14:57:48 by txisto-d         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	count;

	count = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size > 0)
	{
		while (dest_len + count < size - 1 && src[count])
		{
			dest[dest_len + count] = src[count];
			count++;
		}
	}
	dest[dest_len + count] = '\0';
	if (size < dest_len)
		return (src_len + size);
	else
		return (dest_len + src_len);
}
/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	dest[50] = {"0123456"};
	char	src[] = {"5"};
	unsigned int	new_len;
	printf("dest len = %d\n dest content = %s\n", ft_strlen(dest), dest);
	new_len = ft_strlcat(dest, src, 3);
	//new_len = strlcat(dest, src, 3);
	printf("new dest len = %d\n new dest content = %s\n", new_len, dest);
	return (0);
}
*/
