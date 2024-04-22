/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:17:59 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/17 21:17:59 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int n)
{
	unsigned int		i;
	unsigned char		*dest;
	const unsigned char	*sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	i = 1;
	if (dest == NULL && sorc == NULL)
		return (NULL);
	if (sorc < dest)
	{
		while (i <= n)
		{
			dest[n - i] = sorc[n - i];
			i++;
		}
		return (dst);
	}
	while (n > 0)
	{
		*dest++ = *sorc++;
		n--;
	}
	return (dst);
}
/*
int	main(void)
{
	char str[] = "44332";
	char str1[] = "224";
	ft_memmove(str,str1,6);
	printf("ft_memmove: %s\n",str);

	return(0);
}*/