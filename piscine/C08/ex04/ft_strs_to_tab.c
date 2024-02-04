/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:28:38 by txisto-d          #+#    #+#             */
/*   Updated: 2023/08/10 06:38:38 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int		size;
	int		i;
	char	*copy;

	i = 0;
	size = ft_strlen(str);
	copy = (char *) malloc((size + 1) * sizeof(char));
	while (i < size + 1)
		copy[i++] = '\0';
	ft_strcpy(copy, str);
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*struct_array;

	i = 0;
	struct_array = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (struct_array == NULL)
		return (NULL);
	while (i < ac)
	{
		struct_array[i]->size = ft_strlen(av[i]);
		struct_array[i]->str = av[i];
		struct_array[i]->copy = ft_strdup(av[i]);
	}
	if (i == ac)
	{
		struct_array[i]->size = 0;
		struct_array[i]->str = '\0';
		struct_array[i]->copy = '\0';
	}
	return (struct_array);
}
