/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:22:41 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/07/11 21:00:49 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	valor;

	valor = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n == -2147483648)
	{
		valor += ft_putstr("-2147483648");
		return (valor);
	}
	if (n < 0)
	{
		valor += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		valor += ft_putnbr(n / 10);
		valor += ft_putnbr(n % 10);
	}
	else
	{
		valor += ft_putchar(n + 48);
	}
	return (valor);
}
