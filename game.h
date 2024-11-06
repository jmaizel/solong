#ifndef GAME_H
#define GAME_H

#define TILE_SIZE 64

typedef struct s_player
{
    int x;
    int y;
} t_player;

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
    t_player player;
    char **map;
} t_game;

#endif
