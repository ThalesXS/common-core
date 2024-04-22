/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:44:12 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 17:06:49 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_path(t_game *game)
{
	char			**aux_map;
	unsigned int	i;
	unsigned int	j;

	aux_map = ft_calloc(game->map->height, sizeof(char *));
	i = 0;
	while (i < game->map->height)
	{
		aux_map[i] = ft_calloc(game->map->width, sizeof(char));
		j = 0;
		while (j < game->map->width)
		{
			aux_map[i][j] = game->map->map[i][j];
			j++;
		}
		i++;
	}
	if (ft_flood_fill(game, game->map->starting_pos, aux_map))
	{
		ft_free_map(aux_map, game->map->height);
		return (1);
	}
	ft_free_map(aux_map, game->map->height);
	exit(ft_error("No valid path.\n", game));
}

int	ft_flood_fill(t_game *game, int pos[2], char **aux_map)
{
	static unsigned int	collectibles = 0;
	static unsigned int	exits = 0;
	t_map				*map;

	map = game->map;
	if (aux_map[pos[1]][pos[0]] == '1')
		return (0);
	else if (aux_map[pos[1]][pos[0]] == 'C')
		collectibles++;
	else if (aux_map[pos[1]][pos[0]] == 'E')
		exits = 1;
	aux_map[pos[1]][pos[0]] = '1';
	ft_flood_fill(game, (int [2]){pos[0] - 1, pos[1]}, aux_map);
	ft_flood_fill(game, (int [2]){pos[0] + 1, pos[1]}, aux_map);
	ft_flood_fill(game, (int [2]){pos[0], pos[1] - 1}, aux_map);
	ft_flood_fill(game, (int [2]){pos[0], pos[1] + 1}, aux_map);
	if (collectibles == map->num_collectibles && exits)
		return (1);
	return (0);
}

void	ft_free_map(char **map, unsigned int height)
{
	unsigned int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
