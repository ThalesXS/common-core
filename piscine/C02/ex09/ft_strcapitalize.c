/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:20:04 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/31 11:13:55 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_low(char letter);
int	is_up(char letter);
int	is_nbr(char letter);

char	*ft_strcapitalize(char *str)
{
	int	count;
	int	first_l;

	count = 0;
	first_l = 1;
	while (str[count])
	{
		if (is_nbr(str[count]) && first_l)
			first_l = 0;
		else if (is_low(str[count]) && first_l)
		{
			str[count] = str[count] - 32;
			first_l = 0;
		}
		else if (is_up(str[count]) && first_l)
			first_l = 0;
		else if (is_up(str[count]) && !(first_l))
			str[count] += 32;
		if (!(is_up(str[count])
				|| is_nbr(str[count])
				|| is_low(str[count])))
			first_l = 1;
		count++;
	}
	return (str);
}

int	is_nbr(char letter)
{
	int	nbr;

	nbr = 0;
	if ('0' <= letter && letter <= '9')
	{
		nbr = 1;
	}
	return (nbr);
}

int	is_low(char letter)
{
	int	low;

	low = 0;
	if ('a' <= letter && letter <= 'z')
	{
		low = 1;
	}
	return (low);
}

int	is_up(char letter)
{
	int	up;

	up = 0;
	if ('A' <= letter && letter <= 'Z')
	{
		up = 1;
	}
	return (up);
}
/*
#include<stdio.h>

int	main(void)
{
	char teste[] = {"me ChaMo ThalES e tenho 24anos."};
	printf("%s\n", teste);
	ft_strcapitalize(teste);
	printf("%s\n", teste);
}
*/
