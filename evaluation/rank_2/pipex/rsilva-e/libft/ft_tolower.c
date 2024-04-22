/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:06:34 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/13 16:06:34 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		c = c + 32;
	}
	return (c);
}
/*
int main()
{	
	printf("%d\n", ft_tolower(65));
	printf("%d\n", ft_tolower(77));
	printf("%d\n", ft_tolower(47));
	printf("%d\n", ft_tolower(147));
	printf("%d\n", ft_tolower(120));
}*/