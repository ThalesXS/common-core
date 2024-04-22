/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:27:13 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/17 22:27:13 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (unsigned char) c)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (0);
}
/*
#include <string.h>
int	main(void)
{
	char str[] = "12243     55563644";
	
	printf("ft_strrchr:%s\n",ft_strrchr(str,'5'));
	printf("strrchr:%s\n",strrchr(str,'5'));

	return(0);
}*/