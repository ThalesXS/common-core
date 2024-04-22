/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:14:34 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/07/11 21:00:47 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_args(char c, va_list args)
{
	int	valor ;

	valor = 0;
	if (c == 'c')
		valor += ft_putchar(va_arg(args, int));
	if (c == 's')
		valor += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		valor += ft_printf_pointer (va_arg(args, unsigned long));
	if (c == 'd' || c == 'i')
		valor += ft_putnbr (va_arg(args, int));
	if (c == 'u')
		valor += ft_udecimal (va_arg(args, unsigned int));
	if (c == 'X' || c == 'x')
		valor += ft_putnbr_hexa (va_arg(args, unsigned int), c);
	if (c == '%')
		valor += write (1, &c, 1);
	return (valor);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		valor ;
	va_list	args;

	valor = 0;
	i = -1;
	va_start(args, str);
	while (str[++i] != 0)
	{
		if (str[i] == '%')
		{
			valor += ft_args(str[++i], args);
			continue ;
		}
		valor += write(1, &str[i], 1);
	}
	va_end (args);
	return (valor);
}
