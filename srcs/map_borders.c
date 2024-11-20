/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:31:26 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/19 11:33:05 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

int	check_top_bottom_borders(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
		{
			ft_printf("Error\nTop or bottom border is not a wall\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_side_borders(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			ft_printf("Error\nSide borders are not walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	are_map_borders_valid(char **map)
{
	size_t	width;
	size_t	height;

	if (!map || !map[0])
	{
		ft_printf("Error\nEmpty or uninitialized map\n");
		return (0);
	}
	height = 0;
	width = ft_strlen(map[0]);
	while (map[height])
	{
		if (ft_strlen(map[height]) != width)
		{
			ft_printf("Error\nThe map is not rectangular\n");
			return (0);
		}
		height++;
	}
	if (!check_side_borders(map, width, height))
		return (0);
	if (!check_top_bottom_borders(map, width, height))
		return (0);
	return (1);
}
