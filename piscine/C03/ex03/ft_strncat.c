/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:34:07 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 13:43:42 by txisto-d         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	count;
	unsigned int	dest_len;

	dest_len = ft_strlen(dest);
	count = 0;
	while (count < nb && src[count])
	{
		dest[dest_len + count] = src[count];
		count++;
	}
	dest[dest_len + count] = '\0';
	return (dest);
}
/*
#include<stdio.h>
int     main(void)
{
        char    dest[30] = {"Ola, seja bem "};
        char    src[] = {"vindo"};
        printf("dest = %s\n", dest);
        printf("src = %s\n", src);
        printf("final = %s", ft_strncat(dest, src, 5));
        return (0);
}
*/
