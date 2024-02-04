/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:55:15 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/02 20:00:26 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb *= ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
#include <stdlib.h>
int     main(int ac, char **av)
{
	if (ac == 3)
	{
        	printf("%d", ft_recursive_power(atoi(av[1]),atoi(av[2])));
	}
        return (0);
}
*/
