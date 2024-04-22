/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:15:47 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/19 14:15:47 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numb(long int n)
{
	int	elementos;

	elementos = 0;
	if (n < 0)
	{
		n = n *(-1);
		elementos++;
	}
	while (n > 0)
	{
		n = n / 10;
		elementos++;
	}
	return (elementos);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			len;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	len = count_numb(nb);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + 48;
		nb = nb / 10 ;
	}
	return (str);
}
/*
int main(void)
{
	char	*numero;
	int		n;

	n = -2147483648;
	numero = ft_itoa(n);

	printf("%s\n", numero);
}*/