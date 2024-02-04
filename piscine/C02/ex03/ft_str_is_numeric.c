/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:54:07 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 16:47:48 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	only_number;

	only_number = 1;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
		{
			only_number = 0;
		}
		str++;
	}
	return (only_number);
}
/*
#include<stdio.h>
int     main(void)
{
        char    string1[] = {"123125421312"};
        char    string2[] = {"12412512a123135"};

        printf("%d\n", ft_str_is_numeric(string1));
        printf("%d\n", ft_str_is_numeric(string2));
        return(0);
}
*/
