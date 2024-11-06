/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:02:42 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/06 16:32:19 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>

int key_press(int keycode, t_game *game)
{
    if (keycode == 65361) // Touche gauche
        game->player.x--;
    else if (keycode == 65362) // Touche haut
        game->player.y--;
    else if (keycode == 65363) // Touche droite
        game->player.x++;
    else if (keycode == 65364) // Touche bas
        game->player.y++;

    // Mise à jour de la carte, effacer l'ancien 'P', déplacer le joueur, etc.
    if (game->map[game->player.y][game->player.x] == '0')
        game->map[game->player.y][game->player.x] = 'P';
	else if (game->map[game->player.y][game->player.x] == 'P')
        game->map[game->player.y][game->player.x] = '0';
    return (0);
}

void draw_map(t_game *game)
{
    int x, y;

    // Parcourir chaque élément de la carte
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_texture, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_texture, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_texture, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}




