/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:06:06 by resilva           #+#    #+#             */
/*   Updated: 2023/12/08 19:05:35 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static char	*get_next_subs(char *s, char c)
{
	static int	cursor = 0;
	char		*next_subs;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] != c && s[cursor + len])
		len++;
	next_subs = malloc(sizeof(char) * len + 1);
	if (!next_subs)
		return (NULL);
	while (s[cursor] != c && s[cursor])
		next_subs[i++] = s[cursor++];
	next_subs[i] = '\0';
	return (next_subs);
}

static int	count_subs(char *s, char c)
{
	int		count;
	bool	inside_subs;

	count = 0;
	while (*s)
	{
		inside_subs = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!inside_subs)
			{
				count++;
				inside_subs = true;
			}
			s++;
		}
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		i;
	int		len;

	i = 0;
	len = count_subs(s, c);
	if (!len)
		return (NULL);
	result = malloc(sizeof(char *) * (len + 2));
	if (!result)
		return (NULL);
	while (len-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_subs(s, c);
	}
	result[i] = NULL;
	return (result);
}
