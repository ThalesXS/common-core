/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:26:56 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/14 14:26:56 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substring, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((len == 0) && (*substring == '\0'))
		return ((char *)str);
	if (len == 0)
		return (0);
	if (*substring == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] != '\0' && substring[j] != '\0'
			&& i + j < len && str[i + j] == substring[j])
			j++;
		if (substring[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	int x;
	x = 9;
	char str[] = "-Ad999dd898";
	char str1[] = "-999EAA123898";
	char str2[] = "-eee9EAA1299898";
	char str3[] = "-99fff9E898";
	
	char *result1 = ft_strnstr(str, "Ad", x);
	char *result2 = ft_strnstr(str1, "EAA12", x);
	char *result3 = ft_strnstr(str2, "EAA12", x);
	char *result4 = ft_strnstr(str3, "ff9", x);
	

	printf("ft_strnstr: %s\n",result1);
	printf("ft_strnstr:%s\n",result2);
	printf("ft_strnstr:%s\n",result3);
	printf("ft_strnstr:%s\n",result4);

	return(0);

}*/