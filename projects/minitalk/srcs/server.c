/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:22:55 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/16 16:34:09 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

t_message message;

int	main(void)
{
	int					pid;
	struct sigaction	zeroact;
	struct sigaction	oneact;
	sigset_t 			set;

	pid = getpid();
	sigemptyset(&set);
	zeroact.sa_sigaction = ft_zerohandler;
	oneact.sa_sigaction = ft_onehandler;
	zeroact.sa_flags = SA_SIGINFO;
	oneact.sa_flags = SA_SIGINFO;
	zeroact.sa_mask = set;
	oneact.sa_mask = set;
	ft_printf("Server ID: %d\n", pid);
	message.i = 0;
	message.byte = 0;
	message.message = NULL;
	message.received = 0;
	message.pid = 0;
	ft_receive(&zeroact, &oneact);
	return (0);
}

void	ft_zerohandler(int sig, siginfo_t *info, void *nothing)
{
	(void) sig;
	(void) nothing;

	if (!message.pid)
		message.pid = info->si_pid;
	message.byte = message.byte << 1;
	message.i++;
	if (message.i == 8)
	{
		if (!message.byte)
			message.received = 1;
		/*else
			ft_add();*/
		ft_putchar_fd(message.byte, 1);
		message.i = 0;
		message.byte = 0;
	}
	kill(message.pid, SIGUSR2);
}

void	ft_onehandler(int sig, siginfo_t *info, void *nothing)
{
	(void) sig;
	(void) nothing;

	if (!message.pid)
		message.pid = info->si_pid;
	message.byte = message.byte << 1;
	message.byte += 1;
	message.i++;
	if (message.i == 8)
	{
		//ft_add();
		ft_putchar_fd(message.byte, 1);
		message.i = 0;
		message.byte = 0;
	}
	kill(message.pid, SIGUSR2);
}

void	ft_add(void)
{
	char	*aux;
	char	*old;
	size_t	size;

	size = 1;
	if (message.message)
		size = ft_strlen(message.message) + 1;
	aux = (char *) ft_calloc(sizeof(char), size + 1);
	if (message.message)
	{
		old = message.message;
		ft_memcpy(aux, old, size);
		free(old);
	}
	aux[size - 1] = message.byte;
	aux[size] = 0;
	message.message = aux;
}

void	ft_receive(struct sigaction *zeroact, struct sigaction *oneact)
{
	while (1)
	{
		sigaction(SIGUSR1, zeroact, NULL);
		sigaction(SIGUSR2, oneact, NULL);
		if (message.received == 0)
			pause();
		else
		{
			//ft_printf("%s", message.message);
			//free(message.message);
			//message.message = NULL;
			kill(message.pid, SIGUSR1);
			message.received = 0;
			message.pid = 0;
		}
	}
}