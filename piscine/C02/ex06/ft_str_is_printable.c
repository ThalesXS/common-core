/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:13:41 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 16:36:01 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int	is_printable;

	is_printable = 1;
	while (*str)
	{
		if (!(32 <= *str && *str <= 126))
		{
			is_printable = 0;
		}
		str++;
	}
	return (is_printable);
}
/*
#include<stdio.h>
int     main(void)
{
        char    string1[] = {"12312asdAWDAf"};
        char    string2[] = {"1asdAW\rDasg"};

        printf("%d\n", ft_str_is_printable(string1));
        printf("%d\n", ft_str_is_printable(string2));
        return(0);
}
*/
