/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:20:52 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/08 16:30:15 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_map(t_game *game)
{
	int x, y;
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall_texture, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->floor_texture, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_texture, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectible_texture, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit_texture, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
