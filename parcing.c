/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacobmaizel <jacobmaizel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:04:42 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/08 01:24:01 by jacobmaizel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int is_map_rectangular(char **map)
{
    int i;
    int line_length;

    if (!map || !map[0])
    {
        ft_printf("Erreur : carte vide ou non initialisée\n");
        return (0);
    }
    line_length = ft_strlen(map[0]);
    i = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) != line_length)
        {
            ft_printf("Erreur : la carte n'est pas rectangulaire\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int are_map_border_valide(char **map)
{
	int i;
	int start;
	int end;

	start = 0;
	i = 0;
	end = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[start][0] != '1')
		{
			ft_printf("")
		}
	}

}
