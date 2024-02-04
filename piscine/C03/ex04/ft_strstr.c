/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:44:50 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/06 10:22:42 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*save_find;
	char	*save_str;

	if (*to_find == '\0')
		return (str);
	save_find = to_find;
	while (*str)
	{
		to_find = save_find;
		save_str = str;
		while (*to_find && *str && *str == *to_find)
		{
			str++;
			to_find++;
		}
		if (!(*to_find))
			return (save_str);
		else if (*str)
			str++;
	}
	return (0);
}
/*
#include<stdio.h>
#include <string.h>
int	main(void)
{
	char	agulha[] = "oaa";
	char	palheiro[] = "oa";

	printf("%s\n", ft_strstr(palheiro, agulha));
	printf("%s", strstr(palheiro, agulha));
	return (0);
}
*/
