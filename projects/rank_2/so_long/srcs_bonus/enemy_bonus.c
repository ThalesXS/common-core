/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:08:06 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 20:10:40 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy_movement(t_game *game)
{
	static unsigned int	speed = 0;
	unsigned int		i;

	ft_rend_screen(game);
	if (speed++ % 400 == 0)
	{
		i = 0;
		while (i < game->map->num_enemies)
		{
			ft_enemy_move(game, game->map->enemy_pos[i]);
			i++;
		}
	}
	return (0);
}

void	ft_enemy_move(t_game *game, int *enemy)
{
	int	x;
	int	y;
	int	s_x;
	int	s_y;
	int	handle;

	x = enemy[0];
	y = enemy[1];
	s_x = x;
	s_y = y;
	ft_random_move(game, &x, &y);
	handle = ft_enemy_handle_move(game, x, y);
	ft_make_enemy_move(game, handle, (int [2]){x, y}, (int [2]){s_x, s_y});
	if (!handle)
		return ;
	else
	{
		game->map->map[s_y][s_x] = FLOOR;
		enemy[0] = x;
		enemy[1] = y;
		ft_rend_screen(game);
	}
	return ;
}

void	ft_make_enemy_move(t_game *game, int handle, int xy[2], int s_xy[2])
{
	if (handle == 1 && xy[0] > s_xy[0] && game->map->map[xy[1]][xy[0]] == FLOOR)
		game->map->map[xy[1]][xy[0]] = ENEMY_RIGHT;
	else if (handle == 1 && xy[0] < s_xy[0]
		&& game->map->map[xy[1]][xy[0]] == FLOOR)
		game->map->map[xy[1]][xy[0]] = ENEMY_LEFT;
	else if (handle == 1 && game->map->map[xy[1]][xy[0]] == FLOOR)
		game->map->map[xy[1]][xy[0]] = game->map->map[s_xy[1]][s_xy[0]];
}

void	ft_random_move(t_game *game, int *x, int *y)
{
	int			i;
	static int	j = 0;

	j++;
	i = *x + *y + game->map->starting_pos[0] + game->map->starting_pos[1] + j;
	srand(i);
	i = rand() % 4;
	if (i == 0)
		*y -= 1;
	else if (i == 1)
		*y += 1;
	else if (i == 2)
		*x -= 1;
	else if (i == 3)
		*x += 1;
}

int	ft_enemy_handle_move(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == WALL)
		return (0);
	else if (game->map->map[y][x] == COLLECTIBLE)
		return (0);
	else if (game->map->map[y][x] == EXIT)
		return (0);
	else if (game->map->map[y][x] == ENEMY_RIGHT
		|| game->map->map[y][x] == ENEMY_LEFT)
		return (0);
	else if (game->map->map[y][x] == PLAYER_RIGHT
		|| game->map->map[y][x] == PLAYER_LEFT)
	{
		ft_printf("You lost!\n");
		exit(ft_destroy_game(game));
	}
	return (1);
}
