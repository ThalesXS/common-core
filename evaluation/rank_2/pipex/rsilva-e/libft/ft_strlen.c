/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:00:55 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/13 00:00:55 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len = len + 1;
		s = s + 1;
	}
	return (len);
}
/*int main ()
{

	char str[] = "hello mundo";
	char str1[] = "";

	printf("%zu\n",ft_strlen(str));
	printf("%zu\n",ft_strlen(str1));
}*/