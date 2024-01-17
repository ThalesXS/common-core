/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:10:13 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/17 17:34:09 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

void	ft_bitone(int pid)
{
	int	i;

	kill(pid, SIGUSR2);
	i = usleep(500);
	if (i == 0)
		ft_bitone(pid);
}

void	ft_bitzero(int pid)
{
	int	i;

	kill(pid, SIGUSR1);
	i = usleep(500);
	if (i == 0)
		ft_bitzero(pid);
}

void	ft_sus(int sig)
{
	(void) sig;
	ft_putstr_fd("Message succesfully received\n", 1);
}
