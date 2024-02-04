/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:55:25 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/26 12:08:37 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	end_a;

	end_a = *a;
	*a = *a / *b;
	*b = end_a % *b;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 15;
	b = 10;
	printf("a = %d\nb = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
}
*/
