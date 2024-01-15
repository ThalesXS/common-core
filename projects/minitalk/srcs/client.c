/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:37:38 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/15 21:01:58 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	struct sigaction	sus;
	sigset_t			set;

	sus.sa_handler = ft_sus;
	sigemptyset(&set);
	sus.sa_mask = set;
	sus.sa_flags = 0;
	sigaction(SIGUSR1, &sus, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		ft_send(pid, message);
	}
	else if (argc < 3)
		ft_printf("error_00: lack of arguments.");
	else
		ft_printf("error_01: too many arguments.");
}

void	ft_send(int pid, char *message)
{
	int i;
	unsigned int byte;

	i = 0;
	while (message[i])
	{
		byte = message[i];
		ft_bitbybit(pid, byte);
		i++;
	}
	ft_bitbybit(pid, 0);
}

void	ft_bitbybit(int pid, unsigned char byte)
{
	int	i;
	unsigned char save;

	i = 0;
	save = byte;
	while (i < 8)
	{
		byte = save;
		byte = byte << i;
		byte = byte >> (8 - 1);
		if (!byte)
		{
			ft_bitzero(pid);
		}
		else
		{
			ft_bitone(pid);
		}
		i++;
	}
}

void	ft_bitone(int pid)
{
	kill(pid, SIGUSR2);
	usleep(50);
}

void	ft_bitzero(int pid)
{
	kill(pid, SIGUSR1);
	usleep(50);
}

void	ft_sus(int sig)
{
	(void) sig;
	ft_printf("Message succesfully received\n");
}