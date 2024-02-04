/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:05:27 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/06 10:51:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_valid_base(char *base)
{
	int	count;
	int	forward;

	count = 0;
	while (base[count])
	{
		forward = count + 1;
		if (base[count] == '-' || base[count] == '+'
			|| ft_strlen(base) < 2)
			return (0);
		while (base[forward])
		{
			if (base[count] == base[forward])
				return (0);
			forward++;
		}
		count++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (ft_valid_base(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(-nbr, base);
		}
		else if (nbr >= base_len)
		{
			ft_putnbr_base(nbr / base_len, base);
			ft_putnbr_base(nbr % base_len, base);
		}
		else
		{
			ft_putchar(base[nbr]);
		}
	}
}
/*
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_putnbr_base(atoi(av[1]), av[2]);
		ft_putchar('\n');
	}
	return (0);
}
*/
