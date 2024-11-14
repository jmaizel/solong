#ifndef GAME_H
#define GAME_H

#define TILE_SIZE 32

#include <fcntl.h> 
#include <mlx.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_map
{
    char **map;
    int width;
    int height;
} t_map;

typedef struct s_game
{
    void        *mlx;
    void        *win;
    t_map       map;
    void        *wall_texture;
    void        *floor_texture;
    void        *player_texture;
    void        *collectible_texture;
    void        *exit_texture;
    void        *orc_texture;
    t_position  player_pos;
} t_game;

int read_map(const char *filename, t_map *map);
void free_map(char **map);
int is_map_rectangular(char **map);
int are_map_borders_valid(char **map);
int map_contains_only_one_player(char **map);
int map_contains_exit_and_collectible(char **map);
int all_characters_are_valid(char **map);
int check_all(t_game *game,char *map_filename);
void draw_map(t_game *game);
void move_player(t_game *game, int dx, int dy);
void find_player_position(t_game *game);

#endif

