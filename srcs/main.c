/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:24:21 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/07 15:43:25 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *bg_img;         // Image de fond (terrain de foot)
    void    *player_img;     // Sprite du joueur
	void	*defeneur_img;   // Sprite du defenseur
    int     player_x;        // Position x du joueur
    int     player_y;        // Position y du joueurd
} t_game;

int key_press(int keycode, t_game *game)
{
    if (keycode == 53)
        exit(0);
    if (keycode == 0)
        game->player_x -= 10;
    else if (keycode == 13)
        game->player_y -= 10;
    else if (keycode == 2)
        game->player_x += 10;
    else if (keycode == 1)
        game->player_y += 10;
    mlx_put_image_to_window(game->mlx, game->win, game->bg_img, 0, 0);
    mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_x, game->player_y);
    return (0);
}

int main(void)
{
    t_game game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 1920, 1080, "Solong");
    game.bg_img = mlx_xpm_file_to_image(game.mlx, "background.xpm", &(int){0}, &(int){0});
    game.player_img = mlx_xpm_file_to_image(game.mlx, "frame1.xpm", &(int){0}, &(int){0});
    game.player_x = 800;
    game.player_y = 540;
    mlx_put_image_to_window(game.mlx, game.win, game.bg_img, 0, 0);
    mlx_put_image_to_window(game.mlx, game.win, game.player_img, game.player_x, game.player_y);
    mlx_key_hook(game.win, key_press, &game);
    mlx_loop(game.mlx);
    return (0);
}




