/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:02:42 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/07 12:19:56 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65361 && game->map[game->player.y][game->player.x
		- 1] != '1') // Gauche
		game->player.x--;
	else if (keycode == 65362 && game->map[game->player.y
		- 1][game->player.x] != '1') // Haut
		game->player.y--;
	else if (keycode == 65363 && game->map[game->player.y][game->player.x
		+ 1] != '1') // Droite
		game->player.x++;
	else if (keycode == 65364 && game->map[game->player.y
		+ 1][game->player.x] != '1') // Bas
		game->player.y++;
}

t_position first_position(char **map)
{
    t_position pos;
    int x;
    int y;

    pos.x = -1;
    pos.y = -1;

    x = 0;
    while (map[x])
    {
        y = 0;
        while (map[x][y])
        {
            if (map[x][y] == 'P')
            {
                pos.x = x;
                pos.y = y;
                return pos;
            }
            y++;
        }
        x++;
    }

    return pos;
}

t_position map_change(char **map)
{
	t_position pos;
	pos = first_position(map);
	if (pos.x != -1 && pos.y != -1)
	{
		map[pos.x][pos.y] = '0';
		map[game->player.y][game->player.x] = 'p';
	}


}


void	draw_map(t_game *game)
{
	int x, y;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->wall_texture, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->floor_texture, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->player_texture, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
