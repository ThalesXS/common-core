/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:43:42 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/27 16:48:43 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	only_char;

	only_char = 1;
	while (*str)
	{
		if (!(('A' <= *str && *str <= 'Z') || ('a' <= *str && *str <= 'z')))
		{
			only_char = 0;
		}
		str++;
	}
	return (only_char);
}
/*
#include<stdio.h>
int	main(void)
{
	char	string1[] = {"OnlyCharsHere"};
	char	string2[] = {"awdianaWD2das"};

	printf("%d\n", ft_str_is_alpha(string1));
	printf("%d\n", ft_str_is_alpha(string2));
	return(0);
}
*/
