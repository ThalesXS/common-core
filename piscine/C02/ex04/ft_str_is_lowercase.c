/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:01:27 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/31 11:14:16 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	only_lowercase;

	only_lowercase = 1;
	while (*str)
	{
		if (!('a' <= *str && *str <= 'z'))
		{
			only_lowercase = 0;
		}
		str++;
	}
	return (only_lowercase);
}
/*
#include<stdio.h>
int     main(void)
{
        char    string1[] = {"asdbwrqsasf"};
        char    string2[] = {"asdagAawdasfe"};

        printf("%d\n", ft_str_is_lowercase(string1));
        printf("%d\n", ft_str_is_lowercase(string2));
        return(0);
}
*/
