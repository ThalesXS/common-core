/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:52 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/08 15:24:33 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base, char *new_nbr, int i);
long		ft_strlen(char *str);
int		ft_valid_base(char *base);
long		ft_atoi_base(char *str, char *base);
long		check_digits(long nbr, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*new_nbr;
	long	dec_nbr;
	long		digit_count;

	digit_count = 0;
	if (ft_valid_base(base_from) && ft_valid_base(base_to))
	{
		dec_nbr = ft_atoi_base(nbr, base_from);
		digit_count = check_digits(dec_nbr, base_to);
		dec_nbr = ft_atoi_base(nbr, base_from);
		new_nbr = (char *) malloc((digit_count + 1) * sizeof(char));
		ft_putnbr_base(dec_nbr, base_to, new_nbr, digit_count);
	}
	else
		return (NULL);
	return (new_nbr);
}

long	check_digits(long nbr, char *base_to)
{
	long	digit_count;

	digit_count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		digit_count++;
	}
	while (nbr > 0)
	{
		nbr /= ft_strlen(base_to);
		digit_count++;
	}
	return (digit_count);
}

long	ft_equivalent(char c, char *base)
{
	long	count;

	count = 0;
	while (base[count] != c && base[count])
		count++;
	if (base[count] == c)
		return (count);
	else
		return (0);
}

int	ft_nbr_in_base(char c, char *base)
{
	int	i;
	int	exist;

	i = 0;
	exist = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			exist = 1;
		}
		i++;
	}
	return (exist);
}

long	ft_atoi_base(char *str, char *base)
{
	long	ans;
	long	i;
	long	negative;

	i = 0;
	ans = 0;
	negative = 1;
	if (ft_valid_base(base))
	{
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				negative *= -1;
			i++;
		}
		while (str[i] && ft_nbr_in_base(str[i], base))
		{
			ans = ans * ft_strlen(base) + ft_equivalent(str[i], base);
			i++;
		}
	}
	return (ans * negative);
}
/*
int	main(int ac, char **av)
{
	char	c;
	char	*s;

	c = 'x';
	s = &c;
	if (ac == 4)
	{
		s = ft_convert_base(av[1], av[2], av[3]);
		printf("%s\n", s);
	}
	return (0);
}
*/
