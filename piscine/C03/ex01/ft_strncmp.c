/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:40:28 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/01 17:18:21 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		return (0);
	while (count < n - 1 && s1[count] == s2[count] && s1[count] && s2[count])
		count++;
	return (s1[count] - s2[count]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s1[] = {"12345"};
	char s2[] = {"123456"};
	printf("%d\n", ft_strncmp(s1, s2, 5));
	printf("%d", strncmp(s1, s2, 5));
	return (0);
}
*/
