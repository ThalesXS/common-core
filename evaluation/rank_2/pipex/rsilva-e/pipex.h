/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:34:12 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/13 21:38:10 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		i;
	int		fdinfile;
	int		fdoutfile;
	int		fdpipe[2];
	int		id;
	char	*pathname;
	char	*finalpath;
	char	**path;
	char	**cmds;

}t_pipex;

//----------------------PIPE------------------------
void	open_files_init(int argc, char **argv, t_pipex *all);
void	ft_pipe(t_pipex *all);

//----------------------PIPE_UTILS------------------------
void	ft_comand1(t_pipex *all, char **argv, char **env);
void	ft_comand2(t_pipex *all, char **argv, char **env);
void	ft_closefd(t_pipex *all);
void	error_path(t_pipex *all);
void	getfree(t_pipex *all);

//----------------------PATH_NAME------------------------
void	ft_findpath(t_pipex *all, char **env);
void	ft_joinpath(t_pipex *all, int i);
int		getpath(t_pipex *all, char **env);

#endif