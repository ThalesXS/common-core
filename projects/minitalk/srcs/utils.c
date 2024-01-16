/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:10:13 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/16 16:21:59 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

void	ft_bitone(int pid)
{
	kill(pid, SIGUSR2);
	pause();
}

void	ft_bitzero(int pid)
{
	kill(pid, SIGUSR1);
	pause();
}

void	ft_sus(int sig)
{
	(void) sig;
	ft_printf("Message succesfully received\n");
}