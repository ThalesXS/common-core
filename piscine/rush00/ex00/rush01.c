/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:14:30 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/23 15:53:03 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

//Square Printer
void	ft_print(int x, int y, int c_x, int c_y)
{
	if ((c_x == 1 && c_y == 1) || (c_x == x && c_y == y && y != 1 && x != 1))
	{
		ft_putchar('/');
	}
	else if ((c_x == x && c_y == 1) || (c_y == y && c_x == 1))
	{
		ft_putchar(92);
	}
	else if (c_x != 1 && c_x != x && c_y != 1 && c_y != y)
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('*');
	}
	if (c_x == x)
	{
		ft_putchar('\n');
	}
}

//Counter Function
void	ft_counter(int x, int y, int count_x, int count_y)
{
	while (count_y <= y)
	{
		count_x = 1;
		while (count_x <= x)
		{
			ft_print(x, y, count_x, count_y);
			count_x++;
		}
		count_y++;
	}
}

//Main Function
void	rush(int x, int y)
{
	int	count_x;
	int	count_y;

	count_x = 1;
	count_y = 1;
	ft_counter(x, y, count_x, count_y);
}
