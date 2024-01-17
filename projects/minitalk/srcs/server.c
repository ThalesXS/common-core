/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:22:55 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/17 15:52:45 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

t_message	g_message;

int	main(void)
{
	int					pid;
	struct sigaction	zeroact;
	struct sigaction	oneact;
	sigset_t			set;

	pid = getpid();
	sigemptyset(&set);
	zeroact.sa_sigaction = ft_zerohandler;
	oneact.sa_sigaction = ft_onehandler;
	zeroact.sa_flags = SA_SIGINFO;
	oneact.sa_flags = SA_SIGINFO;
	zeroact.sa_mask = set;
	oneact.sa_mask = set;
	ft_printf("Server ID: %d\n", pid);
	g_message.i = 0;
	g_message.byte = 0;
	g_message.received = 0;
	g_message.pid = 0;
	ft_receive(&zeroact, &oneact);
	return (0);
}

void	ft_zerohandler(int sig, siginfo_t *info, void *nothing)
{
	(void) sig;
	(void) nothing;
	if (!g_message.pid)
		g_message.pid = info->si_pid;
	g_message.byte = g_message.byte << 1;
	g_message.i++;
	if (g_message.i == 8)
	{
		if (!g_message.byte)
			g_message.received = 1;
		ft_putchar_fd(g_message.byte, 1);
		g_message.i = 0;
		g_message.byte = 0;
	}
	kill(g_message.pid, SIGUSR2);
}

void	ft_onehandler(int sig, siginfo_t *info, void *nothing)
{
	(void) sig;
	(void) nothing;
	if (!g_message.pid)
		g_message.pid = info->si_pid;
	g_message.byte = g_message.byte << 1;
	g_message.byte += 1;
	g_message.i++;
	if (g_message.i == 8)
	{
		ft_putchar_fd(g_message.byte, 1);
		g_message.i = 0;
		g_message.byte = 0;
	}
	kill(g_message.pid, SIGUSR2);
}

void	ft_receive(struct sigaction *zeroact, struct sigaction *oneact)
{
	int	i;

	while (1)
	{
		sigaction(SIGUSR1, zeroact, NULL);
		sigaction(SIGUSR2, oneact, NULL);
		if (g_message.received == 0)
			pause();
		else
		{
			i = kill(g_message.pid, SIGUSR1);
			if (i == -1)
			{
				ft_putstr_fd("error_01: Failed to send SIGUSR1.", 1);
				exit(1);
			}
			g_message.received = 0;
			g_message.pid = 0;
		}
	}
}
