#ifndef GAME_H
#define GAME_H

#define TILE_SIZE 64

#include <fcntl.h>

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

int read_map(const char *filename, t_map *map);

#endif
