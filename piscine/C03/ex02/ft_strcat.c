/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:00:09 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 13:26:51 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	count;
	int	dest_len;

	dest_len = ft_strlen(dest);
	count = 0;
	while (src[count])
	{
		dest[dest_len + count] = src[count];
		count++;
	}
	dest[dest_len + count] = '\0';
	return (dest);
}
/*
#include<stdio.h>
int	main(void)
{
	char	dest[30] = {"Ola, seja bem "};
	char	src[] = {"vindo"};
	printf("dest = %s\n", dest);
	printf("src = %s\n", src);
	printf("final = %s", ft_strcat(dest, src));
	return (0);
}
*/
