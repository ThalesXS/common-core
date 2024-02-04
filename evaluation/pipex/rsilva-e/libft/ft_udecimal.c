/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:58:13 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/07/15 14:49:42 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_udecimal(unsigned int n)
{
	char	*base;
	int		valor;

	valor = 0;
	base = "0123456789";
	if (n >= 10)
	{
		valor += ft_udecimal(n / 10);
		valor += ft_udecimal(n % 10);
	}
	else
	{
		valor += ft_putchar(base[n]);
	}
	return (valor);
}
