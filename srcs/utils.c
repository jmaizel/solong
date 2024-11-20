/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:30:27 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/20 11:05:09 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_all(t_game *game, char *map_filename)
{
	if (!read_map(map_filename, &game->map)
		|| !is_map_rectangular(game->map.map)
		|| !are_map_borders_valid(game->map.map)
		|| !map_contains_only_one_player(game->map.map)
		|| !map_contains_exit_and_collectible(game->map.map)
		|| !all_characters_are_valid(game->map.map)
		|| !check_valid_path(&game->map))
		return (0);
	return (1);
}

void	close_game(t_game *game)
{
	destroy_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_map(game->map.map);
	exit(0);
}

int	close_window(t_game *game)
{
	close_game(game);
	return (0);
}
