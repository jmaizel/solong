/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:54:08 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/18 13:00:38 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"
#include <mlx.h>

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

void	close_game(t_game *game)
{
	destroy_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_map(game->map.map);
	exit(0);
}

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

int	close_window(t_game *game)
{
	close_game(game);
	return (0);
}

int	main(void)
{
	t_game	game;
	char	*map_filename;

	map_filename = "textures/mapN1.ber";
	ft_memset(&game, 0, sizeof(t_game));
	if (!check_all(&game, map_filename))
		return (free_map(game.map.map), 1);
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
