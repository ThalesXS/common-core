/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:21:15 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/03 11:52:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	next_p;
	int	i;

	if (nb < 3)
		return (2);
	while (nb <= 2147483647)
	{
		if (nb % 2 == 0)
			nb++;
		i = 3;
		next_p = 1;
		while (i <= nb / i)
		{
			if (nb % i == 0)
				next_p = 0;
			i += 2;
		}
		if (next_p == 1)
		{
			return (nb);
		}
		nb++;
	}
	return (nb);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d", ft_find_next_prime(atoi(av[1])));
	return (0);
}
*/
