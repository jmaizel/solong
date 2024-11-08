/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:04:42 by jmaizel           #+#    #+#             */
/*   Updated: 2024/11/08 16:17:45 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_map_rectangular(char **map)
{
	int	i;
	int	line_length;

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

int	are_map_border_valide(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	while (i < width)
	{
		if (map[0][i] != '1')
			return (ft_printf("Erreur : le bord n'est pas un mur\n"), 0);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[height - 1][i] != '1')
			return (ft_printf("Erreur : le bord n'est pas un mur\n"), 0);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (ft_printf("Erreur : le bord n'est pas un mur\n"), 0);
		i++;
	}
	return (1);
}

int	is_map_contain_only_one_p(char **map)
{
	int	height;
	int	width;
	int	p_count;

	height = 0;
	p_count = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == 'P')
				p_count++;
			width++;
		}
		height++;
	}
	if (p_count < 1)
		return (ft_printf("Erreur : Pas de joueur sur la carte\n"), 0);
	else if (p_count > 1)
		return (ft_printf("Erreur : Nombre de positions du joueur invalide\n"),
			0);
	return (1);
}

int	is_map_contain_exit_and_colectible(char **map)
{
	int	height;
	int	width;
	int	e_count;
	int	c_count;

	height = 0;
	e_count = 0;
	c_count = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == 'E')
				e_count++;
			else if (map[height][width] == 'C')
				c_count++;
			width++;
		}
		height++;
	}
	if (e_count < 1)
		return (ft_printf("Erreur : Pas de sortie sur la carte\n"), 0);
	else if (c_count < 1)
		return (ft_printf("Erreur : Pas de collectible sur la carte\n"), 0);
	return (1);
}

int	all_caractere_are_valid(char **map)
{
	int	width;
	int	height;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] != '1' && map[height][width] != '0'
				&& map[height][width] != 'P' && map[height][width] != 'C'
				&& map[height][width] != 'E')
			{
				ft_printf("Erreur : Caractère non valide sur la carte\n");
				return (0);
			}
			width++;
		}
		height++;
	}
	return (1);
}
