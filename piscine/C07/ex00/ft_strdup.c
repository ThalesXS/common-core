/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:52:48 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/07 18:04:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*copy;

	copy = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	return (ft_strcpy(copy, src));
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "Duplicate me";
	char *dp;
	dp = ft_strdup(str);
	printf("%s", dp);
	return (0);
}
*/
