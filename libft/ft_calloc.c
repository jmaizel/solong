/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:05:09 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/16 11:53:29 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			total_size;
	unsigned char	*tmp;

	total_size = count * size;
	i = 0;
	tmp = malloc(sizeof(unsigned char) * (total_size));
	if (!tmp)
		return (0);
	while (i < total_size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
/*
explication fonction : 
calloc alloue de la memoire pour un tableau de count element,
chaque element ayant une taille de size octets,
elle initialise ensuite chaque byte a zero
*/
