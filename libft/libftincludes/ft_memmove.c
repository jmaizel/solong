/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:42:55 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/10/18 11:18:27 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char *) dst;
	j = (unsigned char *) src;
	if (dst == src || n == 0)
		return (dst);
	if (i < j)
	{
		while (n--)
			*i++ = *j++;
	}
	else
	{
		i += n;
		j += n;
		while (n--)
			*(--i) = *(--j);
	}
	return (dst);
}
/*
explication fonction :
copie n octets de la memoire pointee par src vers la memoir pointee par dst
en gerant le cas ou les zones memoirent se chevauchent.
elle renvoie dst si dst et src pointent ver
 la meme zone memoir ou si n est egal a 0.
la fonction renvoie simplement dst sans effectuer la copie.

*/
