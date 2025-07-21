/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:20:52 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/26 20:15:50 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	*get_texture_for_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
	{
		if (x == 0 || y == 0 || x == game->map.width - 1
			|| y == game->map.height - 1)
			return (game->wall[game->current_frame]);
		else
			return (game->barriere_texture);
	}
	else if (tile == '0')
		return (game->floor);
	else if (tile == 'P')
		return (game->player_texture);
	else if (tile == 'C')
		return (game->collectible_texture);
	else
	{
		ft_printf("Erreur : caractère invalide '%c'\n", tile);
		return (0);
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

	game->wall[0] = mlx_xpm_file_to_image(game->mlx, "f1.xpm", &width, &height);
	game->wall[1] = mlx_xpm_file_to_image(game->mlx, "f2.xpm", &width, &height);
	game->wall[2] = mlx_xpm_file_to_image(game->mlx, "f3.xpm", &width, &height);
	game->wall[3] = mlx_xpm_file_to_image(game->mlx, "f4.xpm", &width, &height);
	game->wall[4] = mlx_xpm_file_to_image(game->mlx, "f5.xpm", &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "sol.xpm", &width, &height);
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
	if (!game->wall[0] || !game->wall[1] || !game->wall[2] || !game->wall[3]
		|| !game->wall[4] || !game->floor || !game->player_texture
		|| !game->collectible_texture || !game->exit_texture)
		return (0);
	return (1);
}
