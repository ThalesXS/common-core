/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:28:31 by ecorona-          #+#    #+#             */
/*   Updated: 2023/12/20 14:14:38 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	int			loop;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	loop = 1;
	if (*buf)
		line = read_buf(buf, &loop);
	while (loop)
	{
		line = read_fd(fd, buf, line, &loop);
		if (!line)
			loop = 0;
	}
	return (line);
}

char	*read_buf(char *buf, int *loop)
{
	int		buf_len;
	int		new_line;
	char	*line;

	buf_len = ft_strchr(buf, 0);
	new_line = ft_strchr(buf, '\n');
	if (new_line > 0 && new_line <= buf_len)
	{
		line = ft_calloc(new_line + 1);
		if (!line)
			return (NULL);
		ft_strcpy(line, buf, 0, new_line);
		write_buf(buf, new_line, buf_len);
		*loop = 0;
	}
	else
	{
		line = ft_calloc(buf_len + 1);
		if (!line)
			return (NULL);
		ft_strcpy(line, buf, 0, buf_len);
		write_buf(buf, 0, 0);
	}
	return (line);
}

void	write_buf(char *buf, int start, int end)
{
	int	i;

	i = 0;
	while (start + i < end)
	{
		buf[i] = buf[start + i];
		i++;
	}
	while (i < BUFFER_SIZE)
		buf[i++] = '\0';
}

char	*read_fd(int fd, char *buf, char *line, int *loop)
{
	char	*temp;
	char	*aux;
	int		read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size > 0)
	{
		aux = read_buf(buf, loop);
		temp = line;
		line = ft_strjoin(line, aux);
		ft_free(aux);
		ft_free(temp);
		if (!line)
			return (NULL);
	}
	else
	{
		if (end_of_file(read_size, loop, line) < 0)
			return (NULL);
	}
	return (line);
}

int	end_of_file(int read_size, int *loop, char *line)
{
	*loop = 0;
	if (read_size < 0)
	{
		free(line);
		line = NULL;
		return (-1);
	}
	return (0);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;


	fd = open("test.txt",O_RDONLY);
	i = 1;
	line = (void *)1;
	while (line)
	{
		line =  get_next_line(fd);
		printf("call %i:\n%s\n",i++,line);
		if (line)
		{
			free(line);
			line = (void *)1;
		}
	}
	close(fd);
}
*/
