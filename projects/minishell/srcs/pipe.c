/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:15:14 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/23 19:28:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_child(int *pipe_fd);
static void	ft_parent(int *pipe_fd);

void	ft_pipe(int *num_com, pid_t parent)
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid;

	pid = parent;
	if (*num_com > 1)
	{
		status = pipe(pipe_fd);
		if (status == -1)
			ft_printf("Error creating pipe\n");
		pid = fork();
		if (pid == 0)
		{
			ft_child(pipe_fd);
			(*num_com)--;
			ft_pipe(num_com, pid);
		}
		else
		{
			ft_parent(pipe_fd);
		}
	}
}

static void	ft_child(int *pipe_fd)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
}

static void	ft_parent(int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
}