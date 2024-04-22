/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:43:24 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/18 09:43:24 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen (s) - start)
		len = ft_strlen (s) - start;
	if (start > ft_strlen (s))
		return (ft_strdup (""));
	str = (char *)(malloc((len + 1) * sizeof(char)));
	if (str == NULL)
		return (NULL);
	ft_memcpy (str, s + start, len);
	str[len] = '\0';
	return (str);
}
/*
int main(void)
{
	char str[] ="ABCDEFGHJ123";
	char *p;
	p = ft_substr(str,3,2);
	
	printf ("%s\n",p);
	
}*/