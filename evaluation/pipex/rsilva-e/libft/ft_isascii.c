/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:44:03 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/12 22:44:03 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
	{
		return (1);
	}
	else
		return (0);
}

/*int main ()
{
	printf("%d\n",ft_isascii(48));
	printf("%d\n",ft_isascii(56));
	printf("%d\n",ft_isascii(120));
	printf("%d\n",ft_isascii(11));
	printf("%d\n",ft_isascii(10));
	printf("%d\n",ft_isascii(128));
}*/