/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:11:53 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/19 12:08:23 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"

char	**append_line_to_map(char **map, int line_count, char *line)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (line_count + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_printf("Error\nUnable to open file %s\n", filename);
	return (fd);
}

int	read_lines(int fd, t_map *map)
{
	char	*line;
	int		line_count;
	size_t	len;

	line_count = 0;
	map->map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->map = append_line_to_map(map->map, line_count, line);
		if (!map->map)
			return (free(line), close(fd), 0);
		line_count++;
		line = get_next_line(fd);
	}
	if (line_count == 0)
		return (ft_printf("Error\nThe map is empty\n"), 0);
	map->height = line_count;
	map->width = ft_strlen(map->map[0]);
	return (1);
}

int	read_map(const char *filename, t_map *map)
{
	int	fd;

	fd = open_map_file(filename);
	if (fd < 0)
		return (0);
	if (!read_lines(fd, map))
	{
		close(fd);
		if (map->map)
			free_map(map->map);
		return (0);
	}
	close(fd);
	return (1);
}

void	destroy_textures(t_game *game)
{
	if (game->wall_texture)
		mlx_destroy_image(game->mlx, game->wall_texture);
	if (game->floor_texture)
		mlx_destroy_image(game->mlx, game->floor_texture);
	if (game->player_texture)
		mlx_destroy_image(game->mlx, game->player_texture);
	if (game->collectible_texture)
		mlx_destroy_image(game->mlx, game->collectible_texture);
	if (game->exit_texture)
		mlx_destroy_image(game->mlx, game->exit_texture);
}
