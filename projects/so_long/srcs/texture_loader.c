/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:21:29 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 15:28:49 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_wall_floor(t_game *game)
{
	t_image	*wall;
	t_image	*floor;

	wall = &game->assets->textures[WALL];
	floor = &game->assets->textures[FLOOR];
	wall->img[0] = mlx_xpm_file_to_image(game->connection,
			WALL_PATH, &wall->width, &wall->height);
	floor->img[0] = mlx_xpm_file_to_image(game->connection,
			FLOOR_PATH, &floor->width, &floor->height);
	wall->frames = WALL_FRAMES;
	floor->frames = FLOOR_FRAMES;
}

void	ft_init_player(t_game *game)
{
	int		i;
	char	*path;
	char	*aux;
	t_image	*player_right;
	t_image	*player_left;

	i = 0;
	player_right = &game->assets->textures[PLAYER_RIGHT];
	player_left = &game->assets->textures[PLAYER_LEFT];
	while (i < PLAYER_FRAMES)
	{
		aux = ft_itoa(i);
		path = ft_strjoin(PLAYER_RIGHT_PATH, aux);
		player_right->img[i] = mlx_xpm_file_to_image(game->connection, path,
				&player_right->width, &player_right->height);
		free(path);
		path = ft_strjoin(PLAYER_LEFT_PATH, aux);
		player_left->img[i] = mlx_xpm_file_to_image(game->connection, path,
				&player_left->width, &player_left->height);
		free(path);
		free(aux);
		i++;
	}
	player_right->frames = PLAYER_FRAMES;
	player_left->frames = PLAYER_FRAMES;
}

void	ft_init_collectible(t_game *game)
{
	int		i;
	char	*path;
	char	*aux;
	t_image	*collectible;

	i = 0;
	collectible = &game->assets->textures[COLLECTIBLE];
	while (i < COLLECTIBLE_FRAMES)
	{
		aux = ft_itoa(i);
		path = ft_strjoin(COLLECTIBLE_PATH, aux);
		collectible->img[i] = mlx_xpm_file_to_image(game->connection, path,
				&collectible->width, &collectible->height);
		free(path);
		free(aux);
		i++;
	}
	collectible->frames = COLLECTIBLE_FRAMES;
}

void	ft_init_exit(t_game *game)
{
	int		i;
	char	*path;
	char	*aux;
	t_image	*exit;

	i = 0;
	exit = &game->assets->textures[EXIT];
	while (i < EXIT_FRAMES)
	{
		aux = ft_itoa(i);
		path = ft_strjoin(EXIT_PATH, aux);
		exit->img[i] = mlx_xpm_file_to_image(game->connection, path,
				&exit->width, &exit->height);
		free(path);
		free(aux);
		i++;
	}
	exit->frames = EXIT_FRAMES;
}

void	ft_init_enemy(t_game *game)
{
	int		i;
	char	*path;
	char	*aux;
	t_image	*enemy_right;
	t_image	*enemy_left;

	i = 0;
	enemy_right = &game->assets->textures[ENEMY_RIGHT];
	enemy_left = &game->assets->textures[ENEMY_LEFT];
	while (i < ENEMY_FRAMES)
	{
		aux = ft_itoa(i);
		path = ft_strjoin(ENEMY_RIGHT_PATH, aux);
		enemy_right->img[i] = mlx_xpm_file_to_image(game->connection, path,
				&enemy_right->width, &enemy_right->height);
		free(path);
		path = ft_strjoin(ENEMY_LEFT_PATH, aux);
		enemy_left->img[i] = mlx_xpm_file_to_image(game->connection, path,
				&enemy_left->width, &enemy_left->height);
		free(path);
		free(aux);
		i++;
	}
	enemy_right->frames = ENEMY_FRAMES;
	enemy_left->frames = ENEMY_FRAMES;
}
