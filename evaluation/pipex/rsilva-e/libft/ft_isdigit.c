/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:42:47 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/12 22:42:47 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return (1);
	}
	else
		return (0);
}
/*
int main ()
{
	printf("%d\n",ft_isdigit(48));
	printf("%d\n",ft_isdigit(56));
	printf("%d\n",ft_isdigit(120));
	printf("%d\n",ft_isdigit(11));
	printf("%d\n",ft_isdigit(10));
}*/