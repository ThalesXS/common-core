/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:42:57 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 12:33:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_game		*game;
	t_assets	*assets;

	if (argc != 2)
		return (ft_error("Invalid number of arguments\n", NULL));
	map = ft_calloc(1, sizeof(t_map));
	game = ft_calloc(1, sizeof(t_game));
	assets = ft_calloc(1, sizeof(t_assets));
	game->assets = assets;
	game->map = map;
	game->map->map = ft_read_map(argv[1], game);
	ft_init_all(game);
	return (0);
}

char	**ft_read_map(char *filename, t_game *game)
{
	char			**map;
	char			*aux;
	int				fd;
	unsigned int	i;
	unsigned int	lines;

	i = 0;
	aux = NULL;
	lines = ft_valid_file_and_lines(filename, game);
	game->map->height = lines - 1;
	fd = open(filename, O_RDONLY);
	map = ft_calloc(lines + 1, sizeof(char *));
	while (aux || i == 0)
	{
		aux = get_next_line(fd);
		map[i] = aux;
		i++;
	}
	close(fd);
	if (map[0] == NULL)
		exit(ft_error("Invalid map.\n", game));
	return (map);
}

int	ft_valid_file_and_lines(char *filename, t_game *game)
{
	int		fd;
	int		i;
	char	*ext;

	ext = filename + ft_strlen(filename) - 4;
	if (ext != ft_strnstr(filename, ".ber", ft_strlen(filename)))
		exit(ft_error("Invalid file extension.\n", game));
	else
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit (ft_error("Invalid file.\n", game));
	i = ft_line_count(fd, game);
	close(fd);
	return (i);
}
