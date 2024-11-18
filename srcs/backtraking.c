/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:53:50 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/18 17:40:27 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

static t_position	find_position(char **map)
{
	t_position	pos;
	int			i;
	int			j;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

static int	compter_collectables(char **map, int height, int width)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static char	**copy_map(char **original_map, int height)
{
	char	**new_map;
	int		j;
	int		i;

	j = 0;
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (0);
	while (j < height)
	{
		new_map[j] = ft_strdup(original_map[j]);
		if (!new_map[j])
		{
			i = 0;
			while (i < j)
			{
				free(new_map[i]);
				i++;
			}
			return (free(new_map), NULL);
		}
		j++;
	}
	new_map[j] = NULL;
	return (new_map);
}

void	explore_map(char **map, t_map *map_struct, int x, int y)
{
	if (x < 0 || y < 0 || x >= map_struct->width || y >= map_struct->height
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		map_struct->collectables_count--;
	if (map[y][x] == 'E')
		map_struct->exit_found = 1;
	map[y][x] = 'V';
	explore_map(map, map_struct, x + 1, y);
	explore_map(map, map_struct, x - 1, y);
	explore_map(map, map_struct, x, y + 1);
	explore_map(map, map_struct, x, y - 1);
}

int	check_valid_path(t_map *map_struct)
{
	char		**map_copy;
	t_position	start_pos;
	int			i;

	map_copy = copy_map(map_struct->map, map_struct->height);
	if (!map_copy)
		return (0);
	start_pos = find_position(map_struct->map);
	map_struct->collectables_count = compter_collectables(map_struct->map,
			map_struct->height, map_struct->width);
	map_struct->exit_found = 0;
	explore_map(map_copy, map_struct, start_pos.x, start_pos.y);
	i = 0;
	while (i < map_struct->height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	return (map_struct->collectables_count == 0 && map_struct->exit_found);
}
