#ifndef GAME_H
#define GAME_H

#define TILE_SIZE 64

#include <fcntl.h>
#include <mlx.h>

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_map
{
    char **map;          // La carte sous forme de tableau de lignes
    int width;           // Largeur de la carte (nombre de colonnes)
    int height;          // Hauteur de la carte (nombre de lignes)
    int player_count;    // Nombre de positions de départ (P)
    int exit_count;      // Nombre de sorties (E)
    int collectible_count; // Nombre de collectables (C)
} t_map;

typedef struct s_game
{
    void *mlx;             // Pointeur pour MiniLibX
    void *win;             // Fenêtre de jeu
    t_map map;             // Carte du jeu
    void *wall_texture;    // Texture du mur
    void *floor_texture;   // Texture du sol
    void *player_texture;  // Texture du joueur
    void *collectible_texture; // Texture des collectables
    void *exit_texture;    // Texture de la sortie
    t_position player_pos; // Position du joueur
} t_game;

int read_map(const char *filename, t_map *map);
int	all_caractere_are_valid(char **map);
int	is_map_contain_exit_and_colectible(char **map);
int	is_map_contain_only_one_p(char **map);
int	are_map_border_valide(char **map);
int	is_map_rectangular(char **map);

#endif
