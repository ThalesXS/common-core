/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:20:38 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 19:56:30 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_all(t_game *game)
{
	ft_init_map(game);
	game->connection = mlx_init();
	ft_init_assets(game);
	ft_init_window(game);
	ft_init_game(game);
}

void	ft_init_map(t_game *game)
{
	game->map->width = 0;
	game->map->num_collectibles = 0;
	game->map->num_exits = 0;
	game->map->num_player = 0;
	game->map->starting_pos[0] = 0;
	game->map->starting_pos[1] = 0;
	game->map->num_enemies = 0;
	game->map->enemy_pos = NULL;
	ft_valid_map(game);
	ft_map_to_num(game);
	ft_enemy_position(game);
}

void	ft_init_assets(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
			game->assets->textures[i].img[j++] = NULL;
		i++;
	}
	ft_init_wall_floor(game);
	ft_init_player(game);
	ft_init_collectible(game);
	ft_init_exit(game);
	ft_init_enemy(game);
}

void	ft_init_window(t_game *game)
{
	game->window = mlx_new_window(game->connection,
			game->map->width * TILE_SIZE, game->map->height * TILE_SIZE + 30,
			WINDOW_TITLE);
}

void	ft_init_game(t_game *game)
{
	game->moves = 0;
	ft_rend_screen(game);
	mlx_hook(game->window, 17, 0, ft_close_button, game);
	mlx_key_hook(game->window, ft_key_hook, game);
	mlx_expose_hook(game->window, ft_rend_screen, game);
	mlx_loop_hook(game->connection, ft_enemy_movement, game);
	mlx_loop(game->connection);
}
