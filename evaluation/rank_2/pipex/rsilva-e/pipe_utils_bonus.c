/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:20:48 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/23 18:34:02 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	loop_pipe(int argc, char **argv, char **env, t_pipex *all)
{
	while (++all->i < argc - 2)
	{
		ft_pipe(all);
		all->id = fork();
		if (all->id == -1)
		{
			perror("fork");
			exit(1);
		}
		if (all->id == 0)
		{
			all->cmds = ft_split(argv[all->i], ' ');
			if (getpath(all, env) == 0)
				error_path(all);
			close(all->fdpipe[0]);
			dup2(all->fdpipe[1], STDOUT_FILENO);
			close(all->fdpipe[1]);
			execve(all->finalpath, all->cmds, NULL);
		}
		waitpid(all->id, 0, 0);
		close(all->fdpipe[1]);
		dup2(all->fdpipe[0], STDIN_FILENO);
		close(all->fdpipe[0]);
	}
}

void	ft_closefd(t_pipex *all)
{
	close(all->fdpipe[0]);
	close(all->fdpipe[1]);
	close(all->fdinfile);
	close(all->fdoutfile);
}

void	error_path(t_pipex *all)
{
	ft_closefd(all);
	getfree(all);
	perror("The cmds is not exit");
	exit(EXIT_FAILURE);
}

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

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != 0 || str2[i] != 0)
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}
