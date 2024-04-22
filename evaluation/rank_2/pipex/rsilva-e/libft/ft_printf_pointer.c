/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:35:44 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/07/11 21:00:47 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointhexa(unsigned long n)
{
	char	*base;
	int		valor;

	valor = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		valor += ft_pointhexa(n / 16);
		valor += ft_pointhexa(n % 16);
	}
	else
	{
		valor += ft_putchar(base[n]);
	}
	return (valor);
}

int	ft_printf_pointer(unsigned long n)
{
	int	valor;

	valor = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	valor += write(1, "0x", 2);
	valor += ft_pointhexa(n);
	return (valor);
}
