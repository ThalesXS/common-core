/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:55:39 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/19 11:55:39 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementos, size_t size)
{
	void	*ptr;

	ptr = malloc(elementos * size);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, elementos * size);
	}
	return (ptr);
}
/*
int main()
{
	void *p;
	p = ft_calloc(5,sizeof(int));

	printf("%p\n",p);
	printf("%d\n",((int*)p)[0]);
}*/