/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:56:24 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/23 20:11:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	rush(int x, int y);

//Pow: 10
int	ft_pow(int nb, int pow)
{
	int	count;

	count = 1;
	while (count <= pow)
	{
		nb = nb * 10;
		count ++;
	}
	return (nb);
}

//String Size Check
int	ft_strlen(char *string)
{
	int	count;

	count = 0;
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return (count);
}

//Number Converter
int	ft_nbrconv(char *input)
{
	int	count;
	int	num;

	num = 0;
	count = 0;
	while (input[count] != '\0')
	{
		num = num + ft_pow(input[count] - '0', ft_strlen(input) - count - 1);
		if (!('0' <= input[count] && input[count] <= '9'))
		{
			write(1, "\nERROR: Invalid Parameter.\n", 27);
			return (0);
		}
		if (ft_strlen(input) == 1 && input[count] == '0')
		{
			write(1, "\nERROR: Invalid Parameter.\n", 27);
			return (0);
		}
		count++;
	}
	return (num);
}

//Main Function
int	main(int nb, char **input)
{
	int	x;
	int	y;

	if (nb != 3)
	{
		write(1, "\nERROR: Invalid Number Of Parameters.\n", 38);
		return (0);
	}
	x = ft_nbrconv(input[nb - 2]);
	y = ft_nbrconv(input[nb - 1]);
	rush(x, y);
	return (0);
}
