/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:37:06 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/26 12:23:23 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	aux;
	int	count;

	count = 0;
	while (count < size / 2)
	{
		aux = tab[count];
		tab[count] = tab[size - count - 1];
		tab[size - count - 1] = aux;
		count++;
	}
}
/*
int	main(void)
{
	int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", vet[0], vet[1],
       	vet[2], vet[3], vet[4], vet[5], vet[6], vet[7],
       	vet[8], vet[9], vet[10]);
	ft_rev_int_tab(vet, 11);
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", vet[0], vet[1],
       	vet[2], vet[3], vet[4], vet[5], vet[6], vet[7],
       	vet[8], vet[9], vet[10]);
	return (0);
}
*/
