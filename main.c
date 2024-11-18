/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:54:08 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/18 22:05:36 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 53)
		close_game(game);
	else if (keycode == 0)
		move_player(game, -1, 0);
	else if (keycode == 1)
		move_player(game, 0, 1);
	else if (keycode == 2)
		move_player(game, 1, 0);
	else if (keycode == 13)
		move_player(game, 0, -1);
	return (0);
}

int main(void)
{ 
    t_game game;
    char *map_filename;

    map_filename = "textures/mapN1.ber";
    ft_memset(&game, 0, sizeof(t_game));
    if (!check_all(&game, map_filename))
        return (free_map(game.map.map), 1);
    initialize_collectables_count(&game);
    game.mlx = mlx_init();
    if (!game.mlx)
        return (free_map(game.map.map), 1);

    if (!load_textures(&game))
        return (free_map(game.map.map), 1);
    game.win = mlx_new_window(game.mlx, game.map.width * TILE_SIZE,
            game.map.height * TILE_SIZE, "so_long");
    if (!game.win)
        return (destroy_textures(&game), free_map(game.map.map), 1);
    find_player_position(&game);
    draw_map(&game);
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_loop(game.mlx);
    close_game(&game);
    return (0);
}

