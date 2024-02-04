/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:43 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 16:50:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if ('A' <= str[count] && str[count] <= 'Z')
		{
			str[count] += 32;
		}
		count++;
	}
	return (str);
}
/*
#include<stdio.h>
int     main(void)
{
        char    teste[14] = "Ola Meu AmIGo.";
        printf("%s",ft_strlowcase(teste));
}
*/
