/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 05:36:25 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/31 17:47:39 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*aux;

	aux = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (aux);
}
/*
#include<stdio.h>
int	main(void)
{
	char	dest[] = "ola mundo    wd";
	char	src[] = "HIIIIIIIII";

	printf("%s", ft_strcpy(dest, src));
	return (0);
}
*/
