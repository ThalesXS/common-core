/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:08:29 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 16:37:23 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	only_uppercase;

	only_uppercase = 1;
	while (*str)
	{
		if (!('A' <= *str && *str <= 'Z'))
		{
			only_uppercase = 0;
		}
		str++;
	}
	return (only_uppercase);
}
/*
#include<stdio.h>
int     main(void)
{
        char    string1[] = {"ASDSDBASDFQR"};
        char    string2[] = {"SADFSCVRHGaGASDVR"};

        printf("%d\n", ft_str_is_uppercase(string1));
        printf("%d\n", ft_str_is_uppercase(string2));
        return(0);
}
*/
