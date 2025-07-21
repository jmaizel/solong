/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:58:57 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/26 19:56:44 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define TILE_SIZE 48

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			collectables_count;
	int			exit_found;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	void		*wall;
	void		*floor;
	void		*player_texture;
	int			current_frame;
	int			animation_counter;
	void		*collectible_texture;
	void		*exit_texture;
	void		*barriere_texture;
	void		*exit_ferme_texture;
	int			count_move;
	t_position	player_pos;
}				t_game;

int				read_map(const char *filename, t_map *map);
void			free_map(char **map);
int				is_map_rectangular(char **map);
int				are_map_borders_valid(char **map);
int				map_contains_only_one_player(char **map);
int				map_contains_exit_and_collectible(char **map);
int				all_characters_are_valid(char **map);
int				check_all(t_game *game, char *map_filename);
void			draw_map(t_game *game);
void			move_player(t_game *game, int dx, int dy);
void			find_player_position(t_game *game);
int				check_valid_path(t_map *map_struct);
void			initialize_collectables_count(t_game *game);
void			close_game(t_game *game);
void			destroy_textures(t_game *game);
int				load_textures(t_game *game);
int				handle_keypress(int keycode, t_game *game);
int				close_window(t_game *game);
int				animate_player(t_game *game);
void			draw_tile(t_game *game, int x, int y);

#endif
