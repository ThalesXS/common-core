/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:44:47 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/24 17:28:04 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

//	====================			MACROS			====================

# define MAP_VALID_CHARS "01CEP\n"
# define TILE_SIZE 64
# define WINDOW_TITLE "so_long"

# define FLOOR_FRAMES 1
# define FLOOR_PATH "textures/floor/floor"
# define WALL_FRAMES 1
# define WALL_PATH "textures/wall/wall"
# define PLAYER_FRAMES 4
# define PLAYER_RIGHT_PATH "textures/parrot/right/right_"
# define PLAYER_LEFT_PATH "textures/parrot/left/left_"
# define COLLECTIBLE_FRAMES 4
# define COLLECTIBLE_PATH "textures/egg/egg_"
# define EXIT_FRAMES 8
# define EXIT_PATH "textures/nest/nest_"
# define ENEMY_FRAMES 4
# define ENEMY_RIGHT_PATH "textures/snake/right/right_"
# define ENEMY_LEFT_PATH "textures/snake/left/left_"

# define FLOOR 0
# define WALL 1
# define PLAYER_RIGHT 2
# define PLAYER_LEFT 3
# define COLLECTIBLE 4
# define ENEMY_RIGHT 5
# define ENEMY_LEFT 6
# define EXIT 7

//	====================			structs			====================

typedef struct s_map
{
	char			**map;
	unsigned int	width;
	unsigned int	height;
	unsigned int	num_collectibles;
	unsigned int	num_exits;
	unsigned int	num_player;
	int				starting_pos[2];
}	t_map;

typedef struct s_image
{
	void			*img[8];
	int				width;
	int				height;
	unsigned int	frames;
}	t_image;

typedef struct s_assets
{
	t_image	textures[8];
}	t_assets;

typedef struct s_tile
{
	unsigned int	type;
	unsigned int	frame;
}	t_tile;

typedef struct s_game
{
	void			*connection;
	void			*window;
	t_map			*map;
	t_assets		*assets;
	unsigned int	moves;
}	t_game;

//	====================			map.c			====================

int		ft_valid_map(t_game *game);
void	ft_map_count(t_game *game, char byte, int i, int j);
int		ft_map_size(t_game *game);
int		ft_map_walls(t_game *game);
int		ft_map_tests(t_game *game);

//	====================		flood_fill.c		====================

int		ft_flood_fill(t_game *game, int pos[2], char **aux_map);
int		ft_check_path(t_game *game);
void	ft_free_map(char **map, unsigned int height);

//	====================			utils.c			====================

int		ft_error(char *str, t_game *game);
int		ft_line_count(int fd, t_game *game);
void	ft_map_to_num(t_game *game);

//	====================		initializers.c		====================

void	ft_init_all(t_game *game);
void	ft_init_map(t_game *game);
void	ft_init_assets(t_game *game);
void	ft_init_window(t_game *game);
void	ft_init_game(t_game *game);

//	====================		texture_loader.c	====================

void	ft_init_wall_floor(t_game *game);
void	ft_init_player(t_game *game);
void	ft_init_collectible(t_game *game);
void	ft_init_exit(t_game *game);
void	ft_init_enemy(t_game *game);

//	====================			rend.c			====================

void	ft_rend_tile(t_game *game, int x, int y, t_tile tile);
int		ft_rend_screen(t_game *game);
void	ft_rend_exit(t_game *game, t_tile *tile);

//	====================			so_long.c		====================

char	**ft_read_map(char *filename, t_game *game);
int		ft_valid_file_and_lines(char *filename, t_game *game);

//	====================			hook.c			====================

int		ft_key_hook(int keycode, t_game *game);
int		ft_close_button(t_game *game);

//	====================			move.c			====================

int		ft_move_player(int keycode, t_game *game);
int		ft_handle_move(t_game *game, int x, int y);
void	ft_handle_rend(t_game *game, int x, int y, int s_xy[2]);
void	ft_handle_key(int keycode, int *x, int *y);

//	====================			destroy.c		====================

int		ft_destroy_game(t_game *game);
void	ft_destroy_assets(t_game *game);
void	ft_destroy_map(t_game *game);

#endif