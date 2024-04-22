/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:45:13 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/14 08:45:13 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		c = c - 32;
	}
	return (c);
}

/*int main()
{	
	printf("%c\n", ft_toupper(97));
	printf("%c\n", ft_toupper(111));
	printf("%c\n", ft_toupper(47));
	printf("%c\n", ft_toupper(147));
	printf("%c\n", ft_toupper(120));
}*/