/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:21:08 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/21 17:10:22 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_files(char **argv, t_pipex *all)
{
	all->fdinfile = open(argv[1], O_RDONLY);
	if (all->fdinfile == -1)
	{
		close(all->fdinfile);
		perror("Error: infile");
		exit(EXIT_FAILURE);
	}
	dup2(all->fdinfile, STDIN_FILENO);
	close(all->fdinfile);
	all->pathname = NULL;
	all->finalpath = NULL;
	all->path = NULL;
	all->cmds = NULL;
}

void	ft_pipe(t_pipex *all)
{
	if (pipe(all->fdpipe) == -1)
	{
		close(all->fdinfile);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	all;

	all.i = 1;
	if (argc >= 4 && ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		open_files(argv, &all);
		loop_pipe(argc, argv, env, &all);
		all.cmds = ft_split(argv[all.i], ' ');
		if (getpath(&all, env) == 0)
			error_path(&all);
		all.fdoutfile = open(argv[argc - 1], O_CREAT
				| O_WRONLY | O_TRUNC, 0644);
		dup2(all.fdoutfile, STDOUT_FILENO);
		close(all.fdoutfile);
		execve(all.finalpath, all.cmds, NULL);
		waitpid(all.id, NULL, 0);
	}
	else if (argc == 6 && ft_strncmp (argv[all.i++], "here_doc", 8) == 0)
		here_doc(&all, argc, argv, env);
	else
	{
		printf("Error:\nCmds: ./pipex <file1> <cmdn> <file2>\n");
		printf("here_doc: ./pipex here_doc <LIMITER> <cmd> <cmd1> <file>\n");
	}
	return (0);
}
