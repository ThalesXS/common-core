/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:19:04 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/31 11:18:18 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	ans;
	int	count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] && s2[count])
		count++;
	ans = s1[count] - s2[count];
	return (ans);
}
/*
#include<stdio.h>
int	main(void)
{
	printf("%d", ft_strcmp("ABCD","ABCd"));
	return (0);
}
*/
