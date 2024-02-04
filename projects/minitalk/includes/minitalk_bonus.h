/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:35:29 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 11:59:20 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# define _XOPEN_SOURCE 700
# define _GNU_SOURCE

typedef struct s_message
{
	unsigned char	byte;
	int				i;
	int				received;
	int				pid;
}	t_message;

void	ft_send(int pid, char *message);
void	ft_bitbybit(int pid, unsigned char byte);
void	ft_bitone(int pid);
void	ft_bitzero(int pid);
void	ft_zerohandler(int sig, siginfo_t *info, void *nothing);
void	ft_onehandler(int sig, siginfo_t *info, void *nothing);
void	ft_add(void);
void	ft_receive(struct sigaction *zeroact, struct sigaction *oneact);
void	ft_sus(int sig);
void	ft_roll(int sig);

#endif
