/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:46:51 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/04 12:54:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(ft_destroy_game(game));
	else if (keycode == 'w' || keycode == 'a'
		|| keycode == 's' || keycode == 'd'
		|| keycode == 65362 || keycode == 65364
		|| keycode == 65361 || keycode == 65363)
		ft_move_player(keycode, game);
	return (0);
}

int	ft_close_button(t_game *game)
{
	ft_destroy_game(game);
	exit(0);
	return (0);
}
