/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:30:23 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/24 00:59:39 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_result(char a, char b, char c);

//Testing if its the last Number Possible
int	ft_not_last(char a, char b, char c)
{
	if (a == '7' && b == '8' && c == '9')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

//Main Function with loop to increase the counter value
void	ft_print_comb(void)
{
	char	num0;
	char	num1;
	char	num2;

	num0 = '0';
	while (num0 <= '7')
	{
		num1 = num0 + 1;
		while (num1 <= '8')
		{
			num2 = num1 + 1;
			while (num2 <= '9')
			{
				ft_result(num0, num1, num2);
				num2++;
			}
			num1++;
		}
		num0++;
	}
}

//Print Char Function
void	ft_putchar(char l)
{
	write(1, &l, 1);
}

//Print Full Number
void	ft_result(char a, char b, char c)
{
	if (a != b && b != c && c != a)
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(c);
		if (ft_not_last(a, b, c))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return(0);
}
*/
