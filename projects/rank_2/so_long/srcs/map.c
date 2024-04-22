/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:34:54 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 15:26:16 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_map(t_game *game)
{
	unsigned int	i;
	unsigned int	j;
	t_map			*map;

	i = 0;
	map = game->map;
	ft_map_size(game);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'P')
				exit(ft_error("Invalid entry.\n", game));
			else
				ft_map_count(game, map->map[i][j], i, j);
			j++;
		}
		i++;
	}
	ft_map_tests(game);
	return (1);
}

void	ft_map_count(t_game *game, char byte, int i, int j)
{
	t_map	*map;

	map = game->map;
	if (byte == 'C')
		map->num_collectibles++;
	else if (byte == 'P')
	{
		map->num_player++;
		map->starting_pos[0] = j;
		map->starting_pos[1] = i;
	}
	else if (byte == 'E')
		map->num_exits++;
}

int	ft_map_size(t_game *game)
{
	int		i;
	t_map	*map;

	i = 0;
	map = game->map;
	map->width = ft_line_no_n(map->map[0]);
	if (map->width < 3)
		exit(ft_error("Map too small horizontaly.\n", game));
	while (map->map[i])
	{
		if (ft_line_no_n(map->map[i]) != map->width)
			exit(ft_error("Not a retangular map.\n", game));
		i++;
	}
	return (1);
}

int	ft_map_walls(t_game *game)
{
	t_map			*map;
	unsigned int	i;

	i = -1;
	map = game->map;
	while (++i < map->height)
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			exit(ft_error("Map not surrounded by walls.\n", game));
	i = -1;
	while (++i < map->width)
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			exit(ft_error("Map not surrounded by walls.\n", game));
	return (1);
}

int	ft_map_tests(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (map->num_collectibles == 0)
		exit(ft_error("No collectibles in map.\n", game));
	else if (map->num_exits == 0)
		exit(ft_error("No exits in map.\n", game));
	else if (map->num_exits > 1)
		exit(ft_error("More than one exit in map.\n", game));
	else if (map->num_player == 0)
		exit(ft_error("No player in map.\n", game));
	else if (map->num_player > 1)
		exit(ft_error("More than one player in map.\n", game));
	ft_map_walls(game);
	ft_check_path(game);
	return (1);
}
