/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:42:57 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/12 22:42:57 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (1);
	}
	else if ((c >= 'a') && (c <= 'z'))
	{
		return (1);
	}
	else
		return (0);
}
/*int main ()
{
	printf("%d\n",ft_isapha('3'));
	printf("%d\n",ft_isapha('A'));
	printf("%d\n",ft_isapha('z'));
	printf("%d\n",ft_isapha('#'));
	printf("%d\n",ft_isapha('0'));
}*/