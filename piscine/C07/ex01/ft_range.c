/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:52:49 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/07 10:18:46 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	range = (int *) malloc((max - min) * sizeof(int));
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	*teste;
	int	i;
	int	min;
	int	max;

	teste = &i;
	i = 0;
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	if (argc == 3)
	{
		teste = ft_range(min, max);
		while (min < max)
		{
			printf("%i, ", teste[i]);
			min++;
			i++;
		}
	}
	return (0);
}
*/
