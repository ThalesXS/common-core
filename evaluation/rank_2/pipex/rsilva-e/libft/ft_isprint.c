/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:55:02 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/12 22:55:02 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
	{
		return (1);
	}
	else
		return (0);
}
/*int main ()
{
	printf("%d\n",ft_isprint(48));
	printf("%d\n",ft_isprint(56));
	printf("%d\n",ft_isprint(2));
	printf("%d\n",ft_isprint(10));
}*/