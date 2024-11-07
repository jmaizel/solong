/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:11:53 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/07 17:34:55 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void copy_old_lines(char **old_map, char **new_map, int line_count)
{
    int i = 0;
    while (i < line_count)
    {
        new_map[i] = old_map[i];
        i++;
    }
}

char **allocate_new_map(char **old_map, int line_count, char *line)
{
    char **new_map;

    new_map = (char **)calloc(line_count + 1, sizeof(char *));
    if (!new_map)
    {
        ft_printf("Erreur: Problème d'allocation mémoire\n");
        free(line);
        return (NULL);
    }
    if (old_map)
        copy_old_lines(old_map, new_map, line_count);
    if (old_map)
        free(old_map);
    return (new_map);
}

int open_map_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        ft_printf("Erreur: Impossible d'ouvrir le fichier %s\n", filename);
    return fd;
}

int read_lines(int fd, t_map *map)
{
    char *line;
    int line_count = 0;
    char **new_map;

    while ((line = get_next_line(fd)) != NULL)
    {
        new_map = allocate_new_map(map->map, line_count, line);
        if (!new_map)
        {
            close(fd);
            return (0);
        }
        new_map[line_count] = line;
        map->map = new_map;
        line_count++;
    }
    map->height = line_count;
    if (line_count > 0)
        map->width = strlen(map->map[0]);
    return (1);
}

int read_map(const char *filename, t_map *map)
{
    int fd = open_map_file(filename);
    if (fd < 0)
        return (0);

    if (!read_lines(fd, map))
    {
        close(fd);
        return (0);
    }

    close(fd);
    return (1);
}
