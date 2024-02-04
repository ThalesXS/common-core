/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:19:14 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 12:34:36 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_error(char *str, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (game)
		ft_destroy_game(game);
	return (1);
}

int	ft_line_count(int fd, t_game *game)
{
	char	*aux;
	int		i;

	i = 1;
	aux = get_next_line(fd);
	while (aux)
	{
		free(aux);
		aux = get_next_line(fd);
		i++;
	}
	free(aux);
	if (i < 3)
		exit(ft_error("Map too small verticaly.\n", game));
	return (i);
}

void	ft_map_to_num(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '0')
				game->map->map[y][x] = FLOOR;
			else if (game->map->map[y][x] == '1')
				game->map->map[y][x] = WALL;
			else if (game->map->map[y][x] == 'P')
				game->map->map[y][x] = PLAYER_RIGHT;
			else if (game->map->map[y][x] == 'C')
				game->map->map[y][x] = COLLECTIBLE;
			else if (game->map->map[y][x] == 'E')
				game->map->map[y][x] = EXIT;
			else if (game->map->map[y][x] == 'S')
				game->map->map[y][x] = ENEMY_RIGHT;
			x++;
		}
		y++;
	}
}

void	ft_enemy_position(t_game *game)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = 0;
	y = 0;
	game->map->enemy_pos = malloc(game->map->num_enemies * sizeof(int *));
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == ENEMY_RIGHT)
			{
				game->map->enemy_pos[i] = malloc(2 * sizeof(int));
				game->map->enemy_pos[i][0] = x;
				game->map->enemy_pos[i][1] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}
