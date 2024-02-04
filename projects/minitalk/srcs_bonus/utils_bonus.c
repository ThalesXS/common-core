/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:10:13 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 11:59:00 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft.h"

void	ft_bitone(int pid)
{
	kill(pid, SIGUSR2);
	usleep(500);
}

void	ft_bitzero(int pid)
{
	kill(pid, SIGUSR1);
	usleep(500);
}

void	ft_sus(int sig)
{
	(void) sig;
	ft_putstr_fd("Message succesfully received\n", 1);
}
