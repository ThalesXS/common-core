/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:59:17 by txisto-d          #+#    #+#             */
/*   Updated: 2023/07/26 12:09:52 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

//Unique Char Print
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//Main Function
void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}
/*
int     main(void)
{
        ft_putstr("Hello World!");
}
*/
