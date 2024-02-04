/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:02:28 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/08 15:23:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

long	ft_strlen(char *str)
{
	long	count;

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
			|| ft_strlen(base) < 2
			|| base[count] == ' '
			|| (base[count] >= 9 && base[count] <= 13))
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

void	save_loop(char *new_nbr, int digit, long num, char *base)
{
	long	i;

	i = 0;
	while (num >= ft_strlen(base)
		|| (i == digit - 1 && new_nbr[0] != '-') || i == digit - 2)
	{
		if (num >= ft_strlen(base))
		{
			new_nbr[digit - i - 1] = base[num % ft_strlen(base)];
			num = num / ft_strlen(base);
		}
		else
		{
			if (i == 0 && new_nbr[i] != '-')
			{
				new_nbr[i] = base[num];
			}
			else
			{
				new_nbr[digit - i - 1] = base[num];
			}
		}
		i++;
	}
}

void	ft_putnbr_base(long nbr, char *base, char *new_nbr, long digit)
{
	long		base_len;
	long	num;

	num = nbr;
	base_len = ft_strlen(base);
	if (ft_valid_base(base))
	{
		if (nbr < 0)
		{
			new_nbr[0] = '-';
			num = -num;
		}
		save_loop(new_nbr, digit, num, base);
	}
}
