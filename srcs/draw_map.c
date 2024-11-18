/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:20:52 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/18 22:05:08 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

static void	*get_texture_for_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
	{
		if (x == 0 || x == game->map.width - 1 || y == 0
			|| y == game->map.height - 1)
			return (game->wall_texture);
		else
			return (game->orc_texture);
	}
	else if (tile == '0')
		return (game->floor_texture);
	else if (tile == 'P')
		return (game->player_texture);
	else if (tile == 'C')
		return (game->collectible_texture);
	else if (tile == 'E')
		return (game->exit_texture);
	ft_printf("Error\nInvalid character '%c'\n", tile);
	return (NULL);
}

void draw_map(t_game *game)
{
    int x;
    int y;
    void *texture;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            char tile = game->map.map[y][x];

            if (tile == 'E')
            {
                if (game->map.collectables_count > 0)
                    texture = game->orc_texture;
                else
                    texture = game->exit_texture;
            }
            else
            {
                texture = get_texture_for_tile(game, tile, x, y);
            }
            if (texture)
                mlx_put_image_to_window(game->mlx, game->win, texture, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->wall_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/gros-arbre-jaune.xpm", &width, &height);
	game->floor_texture = mlx_xpm_file_to_image(game->mlx, "textures/sol.xpm",
			&width, &height);
	game->player_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->collectible_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/portail.xpm", &width, &height);
	game->orc_texture = mlx_xpm_file_to_image(game->mlx, "textures/buisson.xpm",
			&width, &height);
	if (!game->wall_texture || !game->floor_texture || !game->player_texture
		|| !game->collectible_texture || !game->exit_texture)
		return (0);
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
