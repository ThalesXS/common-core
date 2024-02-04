/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:52:44 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/26 11:45:00 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	mod;
	int	div;

	a = 15;
	b = 10;
	mod = 0;
	div = 0;
	printf("div = %d\nmod = %d\n", div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("div = %d\nmod = %d\n", div, mod);
	return (0);
}
*/
