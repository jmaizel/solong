/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:30:52 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/19 11:46:13 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

void	initialize_collectables_count(t_game *game)
{
	int	x;
	int	y;

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

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

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
				return ;
			}
			x++;
		}
		y++;
	}
}

int	is_move_valid(t_game *game, int x, int y)
{
	int	tile;

	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (0);
	tile = game->map.map[y][x];
	if (tile == '1')
		return (0);
	if (tile == 'E' && game->map.collectables_count > 0)
		return (0);
	return (1);
}

void	process_target_tile(t_game *game, char tile, int x, int y)
{
	if (tile == 'C')
	{
		game->map.collectables_count--;
		game->map.map[y][x] = '0';
		if (game->map.collectables_count == 0)
			draw_map(game);
	}
	else if (tile == 'E' && game->map.collectables_count == 0)
	{
		close_game(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target_tile;

	new_x = game->player_pos.x + dx;
	new_y = game->player_pos.y + dy;
	if (!is_move_valid(game, new_x, new_y))
		return ;
	target_tile = game->map.map[new_y][new_x];
	process_target_tile(game, target_tile, new_x, new_y);
	if (game->map.map[new_y][new_x] == 'E' && game->map.collectables_count == 0)
		return ;
	game->map.map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.x = new_x;
	game->player_pos.y = new_y;
	game->map.map[new_y][new_x] = 'P';
	draw_map(game);
}
