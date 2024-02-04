/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:34:02 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/21 17:11:11 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files_init(int argc, char **argv, t_pipex *all)
{
	all->fdinfile = open(argv[1], O_RDONLY);
	all->fdoutfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if ((all->fdoutfile == -1) || (all->fdinfile == -1))
	{
		close(all->fdoutfile);
		close(all->fdinfile);
		perror("Error: infile / outfile");
		exit(EXIT_FAILURE);
	}
	all->pathname = NULL;
	all->finalpath = NULL;
	all->path = NULL;
	all->cmds = NULL;
}

void	ft_pipe(t_pipex *all)
{
	if (pipe(all->fdpipe) == -1)
	{
		close(all->fdoutfile);
		close(all->fdinfile);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	all;

	all.i = 2;
	if (argc == 5)
	{
		open_files_init(argc, argv, &all);
		ft_pipe(&all);
		ft_comand1(&all, argv, env);
		getfree(&all);
		all.i = 3;
		ft_comand2(&all, argv, env);
		getfree(&all);
		ft_closefd(&all);
		waitpid(all.id, NULL, 0);
	}
	else
	{
		ft_printf("I need to put in minium 2 comands like that:\n");
		ft_printf("./pipex <infile> <cmd1> <cmd2> <outfile>\n");
	}
	return (0);
}
