/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:37 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 15:30:57 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_player(int keycode, t_game *game)
{
	int	x;
	int	y;
	int	s_x;
	int	s_y;
	int	handle;

	x = game->map->starting_pos[0];
	y = game->map->starting_pos[1];
	s_x = x;
	s_y = y;
	ft_handle_key(keycode, &x, &y);
	handle = ft_handle_move(game, x, y);
	if (handle == 1)
		game->map->map[y][x] = PLAYER_RIGHT;
	else if (handle == 2)
		game->map->map[y][x] = PLAYER_RIGHT + EXIT;
	if (!handle)
		return (0);
	else
		ft_handle_rend(game, x, y, (int [2]){s_x, s_y});
	return (1);
}

int	ft_handle_move(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == WALL)
		return (0);
	else if (game->map->map[y][x] == COLLECTIBLE)
	{
		game->map->map[y][x] = FLOOR;
		game->map->num_collectibles--;
	}
	else if (game->map->map[y][x] == EXIT && game->map->num_collectibles == 0)
	{
		ft_printf("Moves: %d\r", game->moves + 1);
		exit(ft_destroy_game(game));
	}
	else if (game->map->map[y][x] == EXIT && game->map->num_collectibles > 0)
		return (2);
	return (1);
}

void	ft_handle_rend(t_game *game, int x, int y, int s_xy[2])
{
	if (game->map->map[s_xy[1]][s_xy[0]] == PLAYER_RIGHT)
		game->map->map[s_xy[1]][s_xy[0]] = FLOOR;
	else if (game->map->map[s_xy[1]][s_xy[0]] == PLAYER_RIGHT + EXIT)
		game->map->map[s_xy[1]][s_xy[0]] = EXIT;
	game->moves++;
	game->map->starting_pos[0] = x;
	game->map->starting_pos[1] = y;
	ft_rend_screen(game);
	ft_printf("Moves: %d\r", game->moves);
}

void	ft_handle_key(int keycode, int *x, int *y)
{
	if (keycode == 'w' || keycode == 65362)
		(*y)--;
	else if (keycode == 's' || keycode == 65364)
		(*y)++;
	else if (keycode == 'a' || keycode == 65361)
		(*x)--;
	else if (keycode == 'd' || keycode == 65363)
		(*x)++;
}
