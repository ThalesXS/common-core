/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:51:17 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 20:10:15 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_rend_tile(t_game *game, int x, int y, t_tile tile)
{
	void	*img;

	img = game->assets->textures[tile.type].img[tile.frame];
	mlx_put_image_to_window(game->connection, game->window, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

int	ft_rend_screen(t_game *game)
{
	unsigned int		x;
	unsigned int		y;
	t_tile				tile;
	static unsigned int	speed = 0;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			tile.type = game->map->map[y][x];
			if (tile.type == FLOOR || tile.type == WALL || tile.type == EXIT)
				tile.frame = 0;
			else
				tile.frame = game->frame;
			ft_rend_exit(game, &tile);
			ft_rend_tile(game, x, y, tile);
			x++;
		}
		y++;
	}
	ft_speed(game, &speed);
	ft_show_moves(game);
	return (0);
}

void	ft_rend_exit(t_game *game, t_tile *tile)
{
	if (tile->type == EXIT + PLAYER_RIGHT)
	{
		tile->type = EXIT;
		tile->frame = 6;
	}
	else if (tile->type == EXIT + PLAYER_LEFT)
	{
		tile->type = EXIT;
		tile->frame = 3;
	}
	else if (tile->type == EXIT && game->map->num_collectibles == 0)
		tile->frame = 1;
}

void	ft_speed(t_game *game, unsigned int *speed)
{
	if ((*speed)++ % 100 == 0)
		game->frame++;
	if (game->frame == 4)
		game->frame = 0;
}

void	ft_show_moves(t_game *game)
{
	char			*str;
	char			*old;
	unsigned int	i;

	str = ft_itoa(game->moves);
	old = ft_itoa(game->moves - 1);
	if (game->map->width % 2 == 0)
		i = (game->map->width / 2) * 64;
	else
		i = (game->map->width / 2) * 64 + 32;
	mlx_string_put(game->connection, game->window,
		i, game->map->height * 64 + 20, 0x00000000, old);
	mlx_string_put(game->connection, game->window,
		i, game->map->height * 64 + 20, 0x00FFFFFF, str);
	free(str);
	free(old);
}
