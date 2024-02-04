/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:37:38 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/08 16:16:23 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*mal_range;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	mal_range = (int *) malloc((max - min) * sizeof(int));
	if (mal_range == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = mal_range;
	while (min < max)
	{
		mal_range[i] = min;
		min++;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	int	i;
	int	size;
	int	*r;
	int	**range;

	i = 0;
	r = &i;
	range = &r;
	size = ft_ultimate_range(range, 10, 15);
	printf("Size = %d\n", size);
	while (i < size)
	{
		printf("%d, ", range[0][i]);
		i++;
	}
	return (0);
}
*/
