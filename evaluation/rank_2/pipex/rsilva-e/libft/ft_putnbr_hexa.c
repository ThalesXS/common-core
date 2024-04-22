/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:32:32 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/07/15 14:46:54 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa(unsigned long n, int c)
{
	char	*lower_base;
	char	*upper_base;
	int		valor;

	valor = 0;
	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		valor += ft_putnbr_hexa(n / 16, c);
		valor += ft_putnbr_hexa(n % 16, c);
	}
	else
	{
		if (c == 'x')
			valor += ft_putchar(lower_base[n]);
		if (c == 'X')
			valor += ft_putchar(upper_base[n]);
	}
	return (valor);
}
