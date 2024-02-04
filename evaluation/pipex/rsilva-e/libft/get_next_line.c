/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:58:20 by fernacar          #+#    #+#             */
/*   Updated: 2023/10/14 16:36:34 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
}

static void	trim_stash(char **stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while ((*stash)[i] != '\n' && (*stash)[i] != '\0')
		i++;
	if ((*stash)[i] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	new_stash = ft_substr1(*stash, i + 1, ftstrlen1(*stash) - i);
	free(*stash);
	*stash = new_stash;
}

static void	write_to_line(char **line, char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	*line = ft_substr1(stash, 0, i);
}

static void	fill_stash(int fd, char **stash)
{
	char	*read_str;
	int		read_size;
	char	*new_stash;

	while (1)
	{
		read_str = ftcalloc1(BUFFER_SIZE + 1, sizeof(char));
		if (!read_str)
			return ;
		if (ft_strchr1(*stash, '\n'))
			break ;
		read_size = read(fd, read_str, BUFFER_SIZE);
		if (read_size < 0)
			free_stash(stash);
		if (read_size <= 0)
			break ;
		new_stash = gnl_strjoin(*stash, read_str);
		free(*stash);
		*stash = new_stash;
		if (*stash == NULL || read_size < BUFFER_SIZE)
			break ;
		free(read_str);
	}
	free(read_str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0)
	{
		if (stash != NULL)
			free_stash(&stash);
		return (NULL);
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	fill_stash(fd, &stash);
	if (stash == NULL || stash[0] == '\0')
	{
		if (stash != NULL)
			free_stash(&stash);
		return (NULL);
	}
	write_to_line(&line, stash);
	trim_stash(&stash);
	return (line);
}
