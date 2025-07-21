/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:04:42 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/26 20:23:51 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	is_map_rectangular(char **map)
{
	size_t	i;
	size_t	line_length;

	if (!map || !map[0])
	{
		ft_printf("Error\nEmpty or uninitialized map\n");
		return (0);
	}
	line_length = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != line_length)
		{
			ft_printf("Error\nThe map is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_contains_only_one_player(char **map)
{
	int	y;
	int	x;
	int	player_count;

	y = 0;
	player_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count < 1)
		return (ft_printf("Error\nNo player on the map\n"), 0);
	else if (player_count > 1)
		return (ft_printf("Error\nToo many player positions on the map\n"), 0);
	return (1);
}

int	map_contains_exit_and_collectible(char **map)
{
	int	y;
	int	x;
	int	exit_count;
	int	collectible_count;

	y = 0;
	exit_count = 0;
	collectible_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit_count++;
			else if (map[y][x] == 'C')
				collectible_count++;
			x++;
		}
		y++;
	}
	if (exit_count != 1 || collectible_count < 1)
		return (ft_printf("Error\nInvalid count of exit or collectible"), 0);
	return (1);
}

int	all_characters_are_valid(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P'
				&& map[y][x] != 'C' && map[y][x] != 'E')
			{
				ft_printf("Error\nInvalid character '%c' on the map\n",
					map[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
