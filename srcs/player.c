/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:30:52 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/18 21:54:28 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

void initialize_collectables_count(t_game *game)
{
    int x;
    int y;

    game->map.collectables_count = 0;
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.map[y][x] == 'C')
                game->map.collectables_count++;
            x++;
        }
        y++;
    }
}


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
    char target_tile;

    if (new_x < 0 || new_y < 0 || new_x >= game->map.width || new_y >= game->map.height)
        return;
    target_tile = game->map.map[new_y][new_x];
    if (target_tile == '1')
        return;
    if (target_tile == 'E' && game->map.collectables_count > 0)
        return; 
    if (target_tile == 'E' && game->map.collectables_count == 0)
        return (close_game(game));
    if (target_tile == 'C')
    {
        game->map.collectables_count--;
        game->map.map[new_y][new_x] = '0';
        if (game->map.collectables_count == 0)
            draw_map(game); 
    }
    game->map.map[game->player_pos.y][game->player_pos.x] = '0';
    game->player_pos.x = new_x;
    game->player_pos.y = new_y;
    game->map.map[new_y][new_x] = 'P';
    draw_map(game);
}

