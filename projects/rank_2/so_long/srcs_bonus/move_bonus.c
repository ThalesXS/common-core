/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:37 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 12:52:46 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	ft_making_move(game, handle, (int [2]){x, y}, (int [2]){s_x, s_y});
	if (!handle)
		return (0);
	else
		ft_handle_rend(game, x, y, (int [2]){s_x, s_y});
	return (1);
}

void	ft_making_move(t_game *game, int handle, int xy[2], int s_xy[2])
{
	if (handle == 1 && xy[0] > s_xy[0] && game->map->map[xy[1]][xy[0]] == FLOOR)
		game->map->map[xy[1]][xy[0]] = PLAYER_RIGHT;
	else if (handle == 1 && xy[0] < s_xy[0]
		&& game->map->map[xy[1]][xy[0]] == FLOOR)
		game->map->map[xy[1]][xy[0]] = PLAYER_LEFT;
	else if (handle == 2 && (xy[0] > s_xy[0]
			|| (game->map->map[s_xy[1]][s_xy[0]] == PLAYER_RIGHT
			&& xy[0] == s_xy[0])))
		game->map->map[xy[1]][xy[0]] = PLAYER_RIGHT + EXIT;
	else if (handle == 2 && (xy[0] < s_xy[0]
			|| game->map->map[s_xy[1]][s_xy[0]] == PLAYER_LEFT))
		game->map->map[xy[1]][xy[0]] = PLAYER_LEFT + EXIT;
	else if (handle == 1 && (game->map->map[s_xy[1]][s_xy[0]] == PLAYER_RIGHT
		|| game->map->map[s_xy[1]][s_xy[0]] == PLAYER_LEFT))
		game->map->map[xy[1]][xy[0]] = game->map->map[s_xy[1]][s_xy[0]];
	else if (handle == 1
		&& (game->map->map[s_xy[1]][s_xy[0]] == PLAYER_RIGHT + EXIT
		|| game->map->map[s_xy[1]][s_xy[0]] == PLAYER_LEFT + EXIT))
		game->map->map[xy[1]][xy[0]] = game->map->map[s_xy[1]][s_xy[0]] - EXIT;
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
		exit(ft_destroy_game(game));
	else if (game->map->map[y][x] == EXIT && game->map->num_collectibles > 0)
		return (2);
	else if (game->map->map[y][x] == ENEMY_RIGHT
		|| game->map->map[y][x] == ENEMY_LEFT)
	{
		ft_printf("You lost!\n");
		exit(ft_destroy_game(game));
	}
	return (1);
}

void	ft_handle_rend(t_game *game, int x, int y, int s_xy[2])
{
	if (game->map->map[s_xy[1]][s_xy[0]] == PLAYER_RIGHT
		|| game->map->map[s_xy[1]][s_xy[0]] == PLAYER_LEFT)
		game->map->map[s_xy[1]][s_xy[0]] = FLOOR;
	else if (game->map->map[s_xy[1]][s_xy[0]] == PLAYER_RIGHT + EXIT
		|| game->map->map[s_xy[1]][s_xy[0]] == PLAYER_LEFT + EXIT)
		game->map->map[s_xy[1]][s_xy[0]] = EXIT;
	game->moves++;
	game->map->starting_pos[0] = x;
	game->map->starting_pos[1] = y;
	ft_rend_screen(game);
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
