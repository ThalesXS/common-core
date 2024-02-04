/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:37:38 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 11:58:34 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	struct sigaction	sus;
	struct sigaction	roll;
	sigset_t			set;

	sus.sa_handler = ft_sus;
	roll.sa_handler = ft_roll;
	sigemptyset(&set);
	sus.sa_mask = set;
	roll.sa_mask = set;
	sus.sa_flags = 0;
	roll.sa_flags = 0;
	sigaction(SIGUSR1, &sus, NULL);
	sigaction(SIGUSR2, &roll, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		ft_send(pid, message);
	}
	else if (argc < 3)
		ft_putstr_fd("error_00: lack of arguments.\n", 1);
	else
		ft_putstr_fd("error_01: too many arguments.\n", 1);
}

void	ft_send(int pid, char *message)
{
	long long		i;
	unsigned char	byte;

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
	long long		i;
	unsigned char	save;

	i = 0;
	save = byte;
	while (i < 8)
	{
		byte = save;
		byte = byte << i;
		byte = byte >> (8 - 1);
		if (!byte)
			ft_bitzero(pid);
		else
			ft_bitone(pid);
		i++;
	}
}

void	ft_roll(int sig)
{
	(void) sig;
	return ;
}
