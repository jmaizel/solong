/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:30:52 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/13 21:35:25 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void find_player_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.map[y][x] == 'P')
            {
                game->player_pos.x = x;
                game->player_pos.y = y;
                return;
            }
            x++;
        }
        y++;
    }
}


void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_pos.x + dx;
    int new_y = game->player_pos.y + dy;
    if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
        return;

    char next_tile = game->map.map[new_y][new_x];
    if (next_tile == '1')
        return;
    game->map.map[game->player_pos.y][game->player_pos.x] = '0';
    game->map.map[new_y][new_x] = 'P';
    game->player_pos.x = new_x;
    game->player_pos.y = new_y;
    draw_map(game);
}
