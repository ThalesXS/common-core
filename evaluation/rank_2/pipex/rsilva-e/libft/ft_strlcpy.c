/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:15:31 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/09/23 16:19:47 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	nsrc;

	i = 0;
	nsrc = ft_strlen(src);
	if (size == 0)
	{
		return (nsrc);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (nsrc);
}
/*
int main (void)
{
	char dest[] = "12345676";
	char src[] = "S55faff";
	
	int size = 6;
	printf("O numero de carateres é : %zu\n",ft_strlcpy(dest,src,size));
	printf("String destino:%s\n",dest);
	printf("String Source: %s\n",src);
	
}*/
