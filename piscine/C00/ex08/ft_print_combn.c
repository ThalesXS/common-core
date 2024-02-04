/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:37:15 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/21 21:08:58 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

//Unique Char Printer
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//Check Not Last
void	ft_not_last(char n, char m)
{
	if (n == 8 && m == 9)
	{
		ft_putchar('\n');
	}
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

//Main Function
void	ft_print_combn(int n)
{
	int	m;

	if (n > 0 && n < 10)
	{
		ft_print_combn(n - 1);
	}
	else if (n == 0)
	{
		while (n < 10)
		{
			m = n + 1;
			while (m < 10)
			{
				ft_putchar(n + '0');
				ft_putchar(m + '0');
				m++;
				ft_not_last(n, m);
			}
			n++;
		}
	}
}
