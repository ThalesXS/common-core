/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:50:08 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 19:43:21 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_destroy_game(t_game *game)
{
	ft_destroy_assets(game);
	if (game->window)
		mlx_destroy_window(game->connection, game->window);
	if (game->connection)
		mlx_destroy_display(game->connection);
	if (game->map->enemy_pos)
		ft_destroy_enemy(game);
	ft_destroy_map(game);
	free(game->connection);
	free(game);
	return (0);
}

void	ft_destroy_assets(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (game->assets->textures[i].img[j])
				mlx_destroy_image(game->connection,
					game->assets->textures[i].img[j]);
			j++;
		}
		i++;
	}
	free(game->assets);
}

void	ft_destroy_map(t_game *game)
{
	ft_free_map(game->map->map, game->map->height);
	free(game->map);
}

void	ft_destroy_enemy(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->map->num_enemies)
	{
		free(game->map->enemy_pos[i]);
		i++;
	}
	free(game->map->enemy_pos);
}
