/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:51:17 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 15:03:35 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rend_tile(t_game *game, int x, int y, t_tile tile)
{
	void	*img;

	img = game->assets->textures[tile.type].img[tile.frame];
	mlx_put_image_to_window(game->connection, game->window, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

int	ft_rend_screen(t_game *game)
{
	unsigned int	x;
	unsigned int	y;
	t_tile			tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			tile.type = game->map->map[y][x];
			tile.frame = 0;
			ft_rend_exit(game, &tile);
			ft_rend_tile(game, x, y, tile);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_rend_exit(t_game *game, t_tile *tile)
{
	if (tile->type >= EXIT + PLAYER_RIGHT)
	{
		tile->type = EXIT;
		tile->frame = 6;
	}
	else if (tile->type == EXIT && game->map->num_collectibles == 0)
		tile->frame = 1;
}
