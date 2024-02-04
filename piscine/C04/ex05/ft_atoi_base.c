/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:07:31 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/06 10:53:03 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_equivalent(char c, char *base)
{
	int	count;

	count = 0;
	while (base[count] != c && base[count])
		count++;
	if (base[count] == c)
		return (count);
	else
		return (0);
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
			|| base[count] == ' '
			|| base[count] >= 9 && base[count] <= 13
			return (0);
		while (base[forward])
		{
			if (base[forward] == base[count])
				return (0);
			forward++;
		}
		count++;
	}
	return (1);
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

int	ft_atoi_base(char *str, char *base)
{
	int	ans;
	int	i;
	int	negative;

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
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	}
	return (0);
}
*/
