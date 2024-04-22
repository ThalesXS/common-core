/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:55:37 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/14 08:55:37 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str )
{
	int	sinal;
	int	resultado;

	resultado = 0;
	sinal = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		sinal = sinal * (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		resultado = resultado * 10 + *str++ - 48;
	return (resultado * sinal);
}
/*
int	main(void)
{
	char str[] = "##-999##ddd898";
	char str1[] = "    -99##9898";
	char str2[] = "5565";
	char str3[] = "";

	printf("ft_atoi: %d\n",ft_atoi(str));
	printf("ft_atoi:%d\n",ft_atoi(str1));
	printf("ft_atoi:%d\n",ft_atoi(str2));
	printf("ft_atoi:%d\n",ft_atoi(str3));

	printf("Atoi: %d\n",atoi(str));
	printf("Atoi :%d\n",atoi(str1));
	printf("Atoi :%d\n",atoi(str2));
	printf("Atoi :%d\n",atoi(str3));
	return(0);
}*/
