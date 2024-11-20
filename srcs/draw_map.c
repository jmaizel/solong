/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:20:52 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/19 15:03:14 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

void	*get_texture_for_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
	{
		if (x == 0 || y == 0 || x == game->map.width - 1
			|| y == game->map.height - 1)
			return (game->wall_texture);
		else
			return (game->barriere_texture);
	}
	else if (tile == '0')
		return (game->floor_texture);
	else if (tile == 'P')
		return (game->player_texture);
	else if (tile == 'C')
		return (game->collectible_texture);
	else
	{
		ft_printf("Erreur : caractère invalide '%c'\n", tile);
		return (NULL);
	}
}

void	*select_texture(t_game *game, char tile, int x, int y)
{
	if (tile == 'E')
	{
		if (game->map.collectables_count > 0)
			return (game->exit_ferme_texture);
		else
			return (game->exit_texture);
	}
	else
		return (get_texture_for_tile(game, tile, x, y));
}

void	draw_tile(t_game *game, int x, int y)
{
	void	*texture;
	char	tile;

	tile = game->map.map[y][x];
	texture = select_texture(game, tile, x, y);
	if (texture)
		mlx_put_image_to_window(game->mlx, game->win, texture, x * TILE_SIZE, y
			* TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->wall_texture = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->floor_texture = mlx_xpm_file_to_image(game->mlx, "textures/sol.xpm",
			&width, &height);
	game->player_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/player-droite.xpm", &width, &height);
	game->collectible_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/portail-ouvert.xpm", &width, &height);
	game->barriere_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/barriere.xpm", &width, &height);
	game->exit_ferme_texture = mlx_xpm_file_to_image(game->mlx,
			"textures/portail-ferme.xpm", &width, &height);
	if (!game->wall_texture || !game->floor_texture || !game->player_texture
		|| !game->collectible_texture || !game->exit_texture)
		return (0);
	return (1);
}
