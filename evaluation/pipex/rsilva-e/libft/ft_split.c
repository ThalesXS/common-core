/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:09:00 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/28 19:16:50 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	palavras;
	int	i;
	int	diferente;

	i = 0;
	palavras = 0;
	diferente = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && diferente == 0)
		{
			diferente = 1;
			palavras++;
		}
		else if (s[i] == c)
		{
			diferente = 0;
		}
		i++;
	}
	return (palavras);
}

static int	count_letters(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		palavras;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (s == NULL)
		return (NULL);
	palavras = count_word(s, c);
	str = (char **)malloc((palavras + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (i < palavras)
	{
		while (s[x] == c)
			x++;
		str[i] = ft_substr(s, x, count_letters(s, c, x));
		if (str == NULL)
			return (NULL);
		x = x + count_letters(s, c, x);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
int main (void)
{
	char **str = ft_split("hello!zzzzzzzz",'z');
	printf("%s\n",str[0]);
	printf("%s\n",str[1]);
	printf("%s\n",str[2]);
	printf("%s\n",str[3]);
	printf("%s\n",str[4]);
	printf("%s\n",str[5]);
	printf("%s\n",str[6]);
}*/
