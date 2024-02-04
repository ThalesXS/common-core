/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:09:50 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/07 12:11:21 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ans;

	ans = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		ans = ans * nb;
		nb--;
	}
	return (ans);
}
/*
#include <stdio.h>

int	main(void)
{
	int	factorial = 50;
	printf("%d", ft_iterative_factorial(factorial));
	return (0);
}
*/
