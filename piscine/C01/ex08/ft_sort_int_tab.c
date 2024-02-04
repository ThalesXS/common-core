/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 05:11:33 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/26 12:37:21 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	aux;
	int	count_1;
	int	count_2;

	count_1 = 0;
	while (count_1 < size)
	{
		count_2 = count_1 + 1;
		while (count_2 < size)
		{
			if (tab[count_1] > tab[count_2])
			{
				aux = tab[count_1];
				tab[count_1] = tab[count_2];
				tab[count_2] = aux;
			}
			count_2++;
		}
		count_1++;
	}
}
/*
int     main(void)
{
	int vet[] = {50, 10, 25, 13, 34, 5, 6, 27, 18, 9, 10};
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", vet[0], vet[1]
			, vet[2], vet[3], vet[4], vet[5], vet[6]
			, vet[7], vet[8], vet[9], vet[10]);
        ft_sort_int_tab(vet, 11);
        printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", vet[0], vet[1]
			, vet[2], vet[3], vet[4], vet[5], vet[6]
			, vet[7], vet[8], vet[9], vet[10]);
        return (0);
}
*/
