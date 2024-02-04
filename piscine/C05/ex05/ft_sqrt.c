/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:40:33 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/06 10:08:03 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (nb % 10 == 2 || nb % 10 == 3 || nb % 10 == 7 || nb % 10 == 8)
		return (0);
	while (nb > 0)
	{
		nb -= i;
		i += 2;
		count++;
	}
	if (nb == 0)
		return (count);
	return (0);
}
/*
#include <limits.h>
#include <stdio.h>
int	main(void)
{
	int	nbr = 2147395600;
	printf("%d\n", ft_sqrt(nbr));
}
*/
