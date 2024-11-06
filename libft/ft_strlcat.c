/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:43:12 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/10/16 12:17:29 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	j = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = len_dst;
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
/*
concatene une chaine src a une chaine dst
tout en respectant la taille maximume de la destination (dstsize)
*/

/*
int main ()
{
	char *dst = "bonjour"; 
	const char *src = "salut";
	size_t dstsize = 7; 
	size_t res;

	res = ft_strlcat(dst, src, dstsize);
	printf("%zu\n", res); // Affiche la longueur totale requise
	printf("%s\n", dst); // Affiche le contenu de dst
	return (0);
}
*/