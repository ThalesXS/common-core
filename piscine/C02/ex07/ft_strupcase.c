/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:33:18 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 16:50:00 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if ('a' <= str[count] && str[count] <= 'z')
		{
			str[count] -= 32;
		}
		count++;
	}
	return (str);
}
/*
#include<stdio.h>
int	main(void)
{
	char	teste[14] = "Ola Meu Amigo.";
	printf("%s",ft_strupcase(teste));
}
*/
