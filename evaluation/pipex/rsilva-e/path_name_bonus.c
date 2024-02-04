/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_name_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:21:15 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/10/17 21:10:16 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_findpath(t_pipex *all, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp ("PATH=", env[i], 5))
		{
			all->pathname = ft_strtrim (env[i], "PATH=");
			break ;
		}
		i++;
	}
	all->path = ft_split(all->pathname, ':');
}

void	ft_joinpath(t_pipex *all, int i)
{
	char	*tmp;

	tmp = ft_strjoin(all->path[i], "/");
	free(all->path[i]);
	all->path[i] = tmp;
	tmp = ft_strjoin(all->path[i], all->cmds[0]);
	free(all->path[i]);
	all->path[i] = tmp;
}

int	getpath(t_pipex *all, char **env)
{
	int		i;

	i = 0;
	ft_findpath(all, env);
	while (all->path[i])
	{
		ft_joinpath(all, i);
		if (access(all->path[i], F_OK) == 0)
		{
			all->finalpath = ft_strdup(all->path[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
