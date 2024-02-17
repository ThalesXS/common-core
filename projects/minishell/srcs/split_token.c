/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:28:12 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/16 22:37:54 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_stringlen(char *s, char c)
{
	int	len;

	len = 0;
	if (*s == c)
		s++;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);

}

static size_t	ft_stringcount(char const *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s != ' ' && *s)
		{
			i++;
			if (*s == '\'')
				ft_stringlen((char *)s, '\'');
			else if (*s == '\"')
				ft_stringlen((char *)s, '\"');
			else
				ft_stringlen((char *)s, ' ');
		}
	}
	return (i);
}

static void	ft_clean(char **split, size_t i)
{
	size_t	n;

	n = 0;
	while (n < i)
		free(split[n++]);
	free(split);
}

static char	**ft_splitting(char **split, char const *s)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s != ' ' && *s)
		{
			len = ft_stringlen(s, c);
			split[i] = ft_substr(s, 0, len);
			if (!split[i])
			{
				ft_clean(split, i);
				return (NULL);
			}
			s += len;
			i++;
		}
	}
	return (split);
}

char	**ft_split_token(char const *s)
{
	char	*aux;
	char	**split;
	size_t	wc;

	aux = (char *)s;
	wc = ft_stringcount(aux);
	split = (char **) ft_calloc(wc + 1, sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_splitting(split, s);
	if (!split)
		return (NULL);
	return (split);
}
