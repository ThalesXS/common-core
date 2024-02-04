/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:33:54 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/21 17:12:52 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	getfree(t_pipex *all)
{
	int	i;

	if (all->cmds != NULL)
	{
		i = -1;
		while (all->cmds[++i])
			free (all->cmds[i]);
		free (all->cmds);
	}
	if (all->path != NULL)
	{
		i = -1;
		while (all->path[++i])
			free (all->path[i]);
		free (all->path);
	}
	if (all->pathname != NULL)
		free (all->pathname);
	if (all->finalpath != NULL)
		free (all->finalpath);
	all->pathname = NULL;
	all->finalpath = NULL;
	all->path = NULL;
	all->cmds = NULL;
}

void	error_path(t_pipex *all)
{
	ft_closefd(all);
	getfree(all);
	perror("The cmds is not exit");
	exit(EXIT_FAILURE);
}

void	ft_closefd(t_pipex *all)
{
	close(all->fdpipe[0]);
	close(all->fdpipe[1]);
	close(all->fdinfile);
	close(all->fdoutfile);
}

void	ft_comand1(t_pipex *all, char **argv, char **env)
{
	all->cmds = ft_split(argv[all->i], ' ');
	if (getpath(all, env) == 0)
	{
		error_path(all);
	}
	all->id = fork();
	if (all->id == 0)
	{
		close(all->fdpipe[0]);
		dup2(all->fdinfile, STDIN_FILENO);
		dup2(all->fdpipe[1], STDOUT_FILENO);
		ft_closefd(all);
		execve(all->finalpath, all->cmds, NULL);
	}
}

void	ft_comand2(t_pipex *all, char **argv, char **env)
{
	all->cmds = ft_split(argv[all->i], ' ');
	if (getpath(all, env) == 0)
	{
		error_path(all);
	}
	all->id = fork();
	if (all->id == 0)
	{
		close(all->fdpipe[1]);
		dup2(all->fdpipe[0], STDIN_FILENO);
		close(all->fdpipe[0]);
		dup2(all->fdoutfile, STDOUT_FILENO);
		close(all->fdoutfile);
		execve(all->finalpath, all->cmds, NULL);
	}
}
