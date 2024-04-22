/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:24:46 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/22 17:02:47 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != 0)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
/*
int main (void)
{
	char str[]="ddddddd";

	ft_putstr_fd(str,2);
}*/