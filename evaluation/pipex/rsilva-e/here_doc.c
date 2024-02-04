/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:17:17 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/23 18:57:22 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	checkcomand(t_pipex *all, char **argv, char **env)
{
	all->pathname = NULL;
	all->finalpath = NULL;
	all->path = NULL;
	all->cmds = NULL;
	all->i = 3;
	all->cmds = ft_split(argv[all->i], ' ');
	if (getpath(all, env) == 0)
		error_path(all);
	else
		getfree(all);
	all->i = 4;
	all->cmds = ft_split(argv[all->i], ' ');
	if (getpath(all, env) == 0)
		error_path(all);
	else
		getfree(all);
}

void	here_doc_get(t_pipex *all, char **argv)
{
	char	*limiter;
	char	*line;

	all->i = 2;
	limiter = ft_strjoin(argv[all->i], "\n");
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || ft_strcmp(line, limiter) == 0)
		{
			if (line)
				free(line);
			break ;
		}
		ft_putstr_fd(line, all->fdpipe_heredoc[1]);
		free(line);
	}
	free(limiter);
	get_next_line(-1);
}

void	here_doc_child(t_pipex *all, char **argv, char **env)
{
	here_doc_get(all, argv);
	all->i = 3;
	all->cmds = ft_split(argv[all->i], ' ');
	getpath(all, env);
	close(all->fdpipe_heredoc[1]);
	dup2(all->fdpipe_heredoc[0], STDIN_FILENO);
	close(all->fdpipe_heredoc[0]);
	dup2(all->fdpipe[1], STDOUT_FILENO);
	close(all->fdpipe[1]);
	execve(all->finalpath, all->cmds, NULL);
	ft_closefd(all);
	getfree(all);
}

void	last_comand(t_pipex *all, int argc, char **argv, char **env)
{
	all->i = 4;
	dup2(all->fdpipe[0], STDIN_FILENO);
	close(all->fdpipe[0]);
	close(all->fdpipe[1]);
	all->cmds = ft_split(argv[all->i], ' ');
	getpath(all, env);
	all->fdoutfile = open(argv[argc - 1], O_CREAT
			| O_WRONLY | O_TRUNC, 0644);
	dup2(all->fdoutfile, STDOUT_FILENO);
	close(all->fdoutfile);
	execve(all->finalpath, all->cmds, NULL);
	ft_closefd(all);
	getfree(all);
}

void	here_doc(t_pipex *all, int argc, char **argv, char **env)
{
	checkcomand(all, argv, env);
	if (pipe(all->fdpipe) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	all->id = fork();
	if (all->id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (all->id == 0)
	{
		if (pipe(all->fdpipe_heredoc) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		here_doc_child(all, argv, env);
	}
	else
		waitpid(all->id, 0, 0);
	last_comand(all, argc, argv, env);
}
