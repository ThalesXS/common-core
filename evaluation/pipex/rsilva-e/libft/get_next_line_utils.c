/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:59:22 by fernacar          #+#    #+#             */
/*   Updated: 2023/10/21 17:19:46 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ftstrlen1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr1(char *s, int c)
{
	int	i;

	i = 0;
	while (s != NULL && (s[i] || c == '\0'))
	{
		if (s[i] == c)
			return (&(s[i]));
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_length;
	int		s2_length;
	size_t	i;
	size_t	j;

	s1_length = 0;
	if (s1 != NULL)
		s1_length = ftstrlen1(s1);
	s2_length = 0;
	if (s2 != NULL)
		s2_length = ftstrlen1(s2);
	result = ftcalloc1(s1_length + s2_length + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while ((++i || !i) && (s1 != NULL && s1[i]))
		result[i] = s1[i];
	j = -1;
	while ((++j || !j) && (s2 != NULL && s2[j]))
		result[i + j] = s2[j];
	return (result);
}

char	*ft_substr1(char *s, int start, int len)
{
	char	*result;
	int		i;

	if (ftstrlen1(s) - start < len)
		len = ftstrlen1(s) - start;
	if (ftstrlen1(s) < start)
		len = 0;
	result = ftcalloc1(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}

void	*ftcalloc1(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (nmemb--)
		ptr[nmemb] = 0;
	return (ptr);
}
