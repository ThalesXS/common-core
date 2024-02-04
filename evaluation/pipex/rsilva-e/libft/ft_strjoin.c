/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:38:22 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/24 15:54:20 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;

	if (s1 == NULL)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen (s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	start = str;
	while (*s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return (start);
}
/*
int main()
{
	const char str[] = "555";
	const char str1[] = "22233";
	char *res;

    res = ft_strjoin(str, str1);

	printf("A frase fica %s\n", res);	
}*/