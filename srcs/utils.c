/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:30:27 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/11/13 21:36:16 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game.h"

void free_map(char **map)
{
    int i;

    if (!map)
        return;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int check_all(t_game *game, char *map_filename)
{
    if (!read_map(map_filename, &game->map) ||
        !is_map_rectangular(game->map.map) ||
        !are_map_borders_valid(game->map.map) ||
        !map_contains_only_one_player(game->map.map) ||
        !map_contains_exit_and_collectible(game->map.map) ||
        !all_characters_are_valid(game->map.map))
        return (0);
    return (1);
}
