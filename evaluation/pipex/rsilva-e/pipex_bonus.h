/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:34:12 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/23 18:34:45 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		fdpipe_heredoc[2];
	int		id;
	char	*pathname;
	char	*finalpath;
	char	**path;
	char	**cmds;

}t_pipex;

//----------------------PIPE_BONUS------------------------
void	open_files(char **argv, t_pipex *all);
void	ft_pipe(t_pipex *all);

//----------------------PIPE_UTILS_BONUS------------------------
void	loop_pipe(int argc, char **argv, char **env, t_pipex *all);
void	ft_closefd(t_pipex *all);
void	error_path(t_pipex *all);
void	getfree(t_pipex *all);
int		ft_strcmp(const char *str1, const char *str2);
//----------------------PATH_NAME_BONUS------------------------
void	ft_findpath(t_pipex *all, char **env);
void	ft_joinpath(t_pipex *all, int i);
int		getpath(t_pipex *all, char **env);

//----------------------HERE_DOC-------------------------------
void	checkcomand(t_pipex *all, char **argv, char **env);
void	here_doc(t_pipex *all, int argc, char **argv, char **env);
void	here_doc_get(t_pipex *all, char **argv);
void	here_doc_child(t_pipex *all, char **argv, char **env);
void	last_comand(t_pipex *all, int argc, char **argv, char **env);

#endif