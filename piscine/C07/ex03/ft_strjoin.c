/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:01:16 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/08 15:01:28 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_strlen(char *str);

//Concat
char	*ft_strcat(char *dest, char *src)
{
	long	i;
	long	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

//Verify strlength
long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//Count chars inside matrix
long	ft_charcounter(char **strs)
{
	long	chars;
	long	i;
	long	j;

	i = 0;
	chars = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			chars++;
			j++;
		}
		i++;
	}
	return (chars);
}

//"Main" Function
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat;
	long	make;
	int		i;

	i = 0;
	make = ft_charcounter(strs) + (size - 1) * ft_strlen(sep);
	if (size == 0)
		return ((char *) malloc(sizeof(char)));
	cat = (char *) malloc((make + 1) * sizeof(char));
	while (i < size)
	{
		ft_strcat(cat, strs[i]);
		if (!(i == size - 1))
			ft_strcat(cat, sep);
		i++;
	}
	return (cat);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	char	random;
	char	*cated;

	random = 'x';
	cated = &random;
	if (ac >= 1)
	{
		cated = ft_strjoin(ac, av, "-");
		printf("%s", cated);
	}
	return (0);
}
*/
