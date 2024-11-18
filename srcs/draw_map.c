/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:20:52 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/18 21:58:30 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

static void	*get_texture_for_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
	{
		if (x == 0 || x == game->map.width - 1 || y == 0
			|| y == game->map.height - 1)
			return (game->wall_texture);
		else
			return (game->orc_texture);
	}
	else if (tile == '0')
		return (game->floor_texture);
	else if (tile == 'P')
		return (game->player_texture);
	else if (tile == 'C')
		return (game->collectible_texture);
	else if (tile == 'E')
		return (game->exit_texture);
	ft_printf("Error\nInvalid character '%c'\n", tile);
	return (NULL);
}

void draw_map(t_game *game)
{
    int x;
    int y;
    void *texture;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            char tile = game->map.map[y][x];

            if (tile == 'E')
            {
                if (game->map.collectables_count > 0)
                    texture = game->orc_texture;
                else
                    texture = game->exit_texture;
            }
            else
            {
                texture = get_texture_for_tile(game, tile, x, y);
            }
            if (texture)
                mlx_put_image_to_window(game->mlx, game->win, texture, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
