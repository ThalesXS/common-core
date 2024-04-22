/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:43:04 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/12 22:43:04 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (1);
	}
	else if ((c >= 'a') && (c <= 'z'))
	{
		return (1);
	}
	else if ((c >= '0') && (c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int main ()
{
	printf("%d\n",ft_isalnum('3'));
	printf("%d\n",ft_isalnum('A'));
	printf("%d\n",ft_isalnum('z'));
	printf("%d\n",ft_isalnum('#'));
	printf("%d\n",ft_isalnum('0'));
}*/